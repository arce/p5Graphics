#include "p5Structure.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

void (*setup_func)() = NULL;

void (*draw_func)() = NULL;

int _frameCount;

int _frameRate;

int _height;

int _width;

void p5_exit() { done = true; }

void p5_loop() { loop = true; }

void p5_mainLoop() {
	while (loop)
		(*draw_func)();
}

void p5_noLoop() { loop = false; }

void p5_popStyle() {
  Context *tmp = curr;
  curr = curr->next;

  vgSetParameterfv(fillPaint, VG_PAINT_COLOR, 4, &(curr->fillColor));
  vgSetParameterfv(strokePaint, VG_PAINT_COLOR, 4, &(curr->strokeColor));

  vgSetf(VG_STROKE_LINE_WIDTH, curr->strokeWeight);
  vgSeti(VG_STROKE_CAP_STYLE, curr->strokeCap);
  vgSeti(VG_STROKE_JOIN_STYLE, curr->strokeJoin);
  vgSetf(VG_STROKE_MITER_LIMIT, curr->strokeMiter);
  free(tmp);
}

void p5_pushStyle() {
  Context *tmp;
  tmp = malloc(sizeof(Context));
  memset(tmp, 0, sizeof(Context));

  tmp->fillColor = vgGetColor(fillPaint);
  tmp->strokeColor = vgGetColor(strokePaint);
  tmp->strokeWeight = vgGetf(VG_STROKE_LINE_WIDTH);
  tmp->strokeCap = vgGeti(VG_STROKE_CAP_STYLE);
  tmp->strokeJoin = vgGeti(VG_STROKE_JOIN_STYLE);
  tmp->strokeMiter = vgGetf(VG_STROKE_MITER_LIMIT);
  tmp->next = curr;
  curr = tmp;
}

void p5_redraw() {}

double p5_time() {
  struct timeval tv;
  double t;
  gettimeofday(&tv, NULL);
  t = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
  return t;
}

void p5_setupFunc(void (*func)()) { setup_func = func; }

void p5_drawFunc(void (*func)()) { draw_func = func; }

int p5_init(int w, int h) {
	vgCreateContextSH(w,h);
  VGfloat RGBA[4];
  int32_t clearColor = 0xAAAAAAFF;

  float width = w;
  float height = h;
  strokePaint = vgCreatePaint();
  vgSetParameteri(strokePaint, VG_PAINT_TYPE, VG_PAINT_TYPE_COLOR);

  fillPaint = vgCreatePaint();
  vgSetParameteri(fillPaint, VG_PAINT_TYPE, VG_PAINT_TYPE_COLOR);

  createPaths();

  _splitColor(RGBA, clearColor);
  vgSetfv(VG_CLEAR_COLOR, 4, RGBA);
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
  vgClear(0, 0, width, height);
  vgSeti(VG_RENDERING_QUALITY, VG_RENDERING_QUALITY_FASTER);
	if (*setup_func!=NULL)
		(*setup_func)();
}

int p5_frameCount() { return _frameCount; }

int p5_frameRate(int rate) {
  if (rate != 0)
    _frameRate = rate;
  return _frameRate;
}

void p5_fullScreen() {}

int p5_height() { return _height; }

void p5_noSmooth() {}

void p5_size(int width, int height) {
  _width = width;
  _height = height;
}

void p5_smooth() {}

int p5_width() { return _width; }
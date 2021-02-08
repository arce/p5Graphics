#include "p5Structure.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

extern struct Style *curr;

void (*setup_func)() = NULL;

void (*draw_func)() = NULL;

void (*size_func)(int w, int h) = NULL;

int _frameCount;

int _frameRate;

void p5_exit() { done = true; }

void p5_loop() { loop = true; }

VGfloat reset[] = {1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0, 1.0f};

void p5_mainLoop() {
  while (loop) {
    p5_processEvents();
    vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
    vgLoadMatrix(reset);
    vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
    vgLoadMatrix(reset);
    (*draw_func)();
    vgFinish();
    _frameCount++;
    p5_cleanEvents();
  }
}

void p5_noLoop() { loop = false; }

Style *newStyle() {
  Style *tmp;
  tmp = malloc(sizeof(Style));
  memset(tmp, 0, sizeof(Style));

  tmp->fillColor = 0xFFFFFFFF;
  tmp->strokeColor = 0x000000FF;
  tmp->fillEnable = VG_FILL_PATH;
  tmp->strokeEnable = VG_STROKE_PATH;
  tmp->strokeWeight = 1;
  tmp->strokeCap = vgGeti(VG_STROKE_CAP_STYLE);
  tmp->strokeJoin = vgGeti(VG_STROKE_JOIN_STYLE);
  tmp->strokeMiter = vgGetf(VG_STROKE_MITER_LIMIT);
  tmp->rectMode = P5_CORNER;
  tmp->ellipseMode = P5_CENTER;
  tmp->shapeMode = P5_CORNER;
  tmp->textMode = P5_MODEL;
  tmp->alignX = P5_LEFT;
  tmp->alignY = P5_BASELINE;
  tmp->fontId = 0;
  tmp->next = NULL;
  return tmp;
}

void p5_popStyle() {
  Style *tmp = curr;
  curr = curr->next;

  vgSetColor(fillPaint, curr->fillColor);
  vgSetPaint(fillPaint, VG_FILL_PATH);

  vgSetColor(strokePaint, curr->strokeColor);
  vgSetPaint(strokePaint, VG_STROKE_PATH);

  vgSetf(VG_STROKE_LINE_WIDTH, curr->strokeWeight);
  vgSeti(VG_STROKE_CAP_STYLE, curr->strokeCap);
  vgSeti(VG_STROKE_JOIN_STYLE, curr->strokeJoin);
  vgSetf(VG_STROKE_MITER_LIMIT, curr->strokeMiter);

  free(tmp);
}

void p5_pushStyle() {
  Style *tmp;
  tmp = malloc(sizeof(Style));
  memset(tmp, 0, sizeof(Style));

  tmp->fillColor = curr->fillColor;
  tmp->strokeColor = curr->strokeColor;
  tmp->fillEnable = curr->fillEnable;
  tmp->strokeEnable = curr->strokeEnable;
  tmp->strokeWeight = curr->strokeWeight;
  tmp->strokeCap = curr->strokeCap;
  tmp->strokeJoin = curr->strokeJoin;
  tmp->strokeMiter = curr->strokeMiter;
  tmp->rectMode = curr->rectMode;
  tmp->ellipseMode = curr->ellipseMode;
  tmp->shapeMode = curr->shapeMode;
  tmp->textMode = curr->textMode;
  tmp->alignX = curr->alignX;
  tmp->alignY = curr->alignY;
  tmp->fontId = curr->fontId;
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

void p5_sizeFunc(void (*func)(int w, int h)) { size_func = func; }

int p5_init(int w, int h) {
  vgCreateContextSH(w, h);

  VGfloat RGBA[4];
  int32_t clearColor = 0xAAAAAAFF;

  _width = w;
  _height = h;
  reset[7] = _height;
  strokePaint = vgCreatePaint();
  vgSetParameteri(strokePaint, VG_PAINT_TYPE, VG_PAINT_TYPE_COLOR);

  fillPaint = vgCreatePaint();
  vgSetParameteri(fillPaint, VG_PAINT_TYPE, VG_PAINT_TYPE_COLOR);

  curr = newStyle();
  p5_pushStyle();
  p5_popStyle();
  createPaths();

  _splitColor(RGBA, clearColor);
  vgSetfv(VG_CLEAR_COLOR, 4, RGBA);
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
  vgClear(0, 0, _width, _height);
  vgSeti(VG_RENDERING_QUALITY, VG_RENDERING_QUALITY_FASTER);
  if (*setup_func != NULL)
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
  reset[7] = _height;
  (*size_func)(width, height);
  vgResizeSurfaceSH(width, height);
}

void p5_smooth() {}

int p5_width() { return _width; }
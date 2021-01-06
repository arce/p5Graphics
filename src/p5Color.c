#include "p5Color.h"
#include <stdbool.h>

void _splitColor(float *arr, int32_t color) {
  arr[0] = ((color >> 24) & 0xFF) / 255.0;
  arr[1] = ((color >> 16) & 0xFF) / 255.0;
  arr[2] = ((color >> 8) & 0xFF) / 255.0;
  arr[3] = ((color)&0xFF) / 255.0;
}

void p5_background(int32_t rgba) {
  float color[4];
  _splitColor(color, rgba);
  vgSeti(VG_SCISSORING, VG_FALSE);
  vgSetfv(VG_CLEAR_COLOR, 4, color);
  vgClear(0, 0,p5_width(), p5_height());
}

void p5_fill(int32_t rgba) {
  curr->fillColor = rgba;
  vgSetColor(fillPaint, curr->fillColor);
  vgSetPaint(fillPaint, VG_FILL_PATH);
  curr->fillEnable = VG_FILL_PATH;
}

void p5_noFill() {
  curr->fillColor = 0;
  curr->fillEnable = 0;
}

void p5_noStroke() {
  curr->strokeColor = 0;
  curr->strokeEnable = 0;
}

void p5_stroke(int32_t rgba) {
  curr->strokeColor = rgba;
  vgSetColor(strokePaint, curr->strokeColor);
  vgSetPaint(strokePaint, VG_STROKE_PATH);
  curr->strokeEnable = VG_STROKE_PATH;
}

int p5_alpha(int32_t rgba) { return ((rgba)&0xFF); }

int p5_blue(int32_t rgba) { return ((rgba >> 8) & 0xFF); }

int32_t p5_color(int r, int g, int b, int a) {
  int32_t rgba =
      ((r & 0xFF) << 24) + ((g & 0xFF) << 16) + ((b & 0xFF) << 8) + (a & 0xFF);
  return rgba;
}

int p5_green(int32_t rgba) { return ((rgba >> 16) & 0xFF); }

int32_t p5_lerpColor(int32_t ca, int32_t cb, float t) {

  int8_t ar = ((ca >> 24) & 0xFF);
  int8_t ag = ((ca >> 16) & 0xFF);
  int8_t ab = ((ca >> 8) & 0xFF);
  int8_t aa = ((ca)&0xFF);

  int8_t br = ((cb >> 24) & 0xFF);
  int8_t bg = ((cb >> 16) & 0xFF);
  int8_t bb = ((cb >> 8) & 0xFF);
  int8_t ba = ((cb)&0xFF);

  int8_t r = ar + (br - ar) * t;
  int8_t g = ag + (bg - ag) * t;
  int8_t b = ab + (bb - ab) * t;
  int8_t a = aa + (ba - aa) * t;

  return p5_color(r, g, b, a);
}

int p5_red(int32_t rgba) { return ((rgba >> 24) & 0xFF); }

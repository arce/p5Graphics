#include "p5Color.h"
#include <stdbool.h>

struct Style *curr;

int p5_width();

int p5_height();

void _splitColor(float *arr, int32_t color) {
  arr[0] = (color & 0xFF000000) / 255.0;
  arr[1] = (color & 0x00FF0000) / 255.0;
  arr[2] = (color & 0x0000FF00) / 255.0;
  arr[3] = (color & 0x000000FF) / 255.0;
}

inline uint32_t toRGBA(uint32_t argb) {
  if (argb < 256)
    return
      ((argb & 0xFF) << 24) |
      ((argb & 0xFF) << 16) |
      ((argb & 0xFF) << 8) |
      ((0xFF) << 0);
  else return
      ((argb & 0xFF000000) >> 24) |
      ((argb & 0x00FF0000) << 8) |
      ((argb & 0x0000FF00) << 8) |
      ((argb & 0x000000FF) << 8);
}

void p5_background(int32_t argb) {
  float color[4];
  _splitColor(color,toRGBA(argb));
  vgSeti(VG_SCISSORING, VG_FALSE);
  vgSetfv(VG_CLEAR_COLOR, 4, color);
  vgClear(0, 0, p5_width(), p5_height());
}

void p5_fill(int32_t argb) {
  curr->fillColor = toRGBA(argb);
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

void p5_stroke(int32_t argb) {
  curr->strokeColor = toRGBA(argb);
  vgSetColor(strokePaint, curr->strokeColor);
  vgSetPaint(strokePaint, VG_STROKE_PATH);
  curr->strokeEnable = VG_STROKE_PATH;
}

int p5_alpha(int32_t rgba) { return ((rgba)&0xFF); }

int p5_blue(int32_t rgba) { return ((rgba >> 8) & 0xFF); }

int32_t p5_color(int r, int g, int b, int a) {
  int32_t argb =
      ((a & 0xFF) << 24) |
      ((r & 0xFF) << 16) |
      ((g & 0xFF) << 8) |
      (b & 0xFF);
  return argb;
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

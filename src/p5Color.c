#include "p5Color.h"
#include "p5Environment.h"

static void _splitColor(float *arr, int32_t color) {
  arr[0] = ((color >> 24) & 0xFF) / 255.0;
  arr[1] = ((color >> 16) & 0xFF) / 255.0;
  arr[2] = ((color >> 8) & 0xFF) / 255.0;
  arr[3] = ((color)&0xFF) / 255.0;
}

static void p5_background(int32_t rgba) {
  float color[4];
  _splitColor(color, rgba);
  vgSeti(VG_SCISSORING, VG_FALSE);
  vgSetfv(VG_CLEAR_COLOR, 4, color);
  vgClear(0, 0,_width,_height);
}

static void p5_fill(int32_t rgba) {
  if (rgba == fillColor)
    return;
  fillColor = rgba;
  vgSetColor(fillPaint, fillColor);
  vgSetPaint(fillPaint, VG_FILL_PATH);
  fillEnable = VG_FILL_PATH;
}

static void p5_noFill() {
  fillColor = 0;
  fillEnable = 0;
}

static void p5_noStroke() {
  strokeColor = 0;
  strokeEnable = 0;
}

static void p5_stroke(int32_t rgba) {
  if (rgba == strokeColor)
    return;
  strokeColor = rgba;
  vgSetColor(strokePaint, strokeColor);
  vgSetPaint(strokePaint, VG_STROKE_PATH);
  strokeEnable = VG_STROKE_PATH;
}

static int p5_alpha(int32_t rgba) { return ((rgba)&0xFF); }

static int p5_blue(int32_t rgba) { return ((rgba >> 8) & 0xFF); }

static int32_t p5_color(int r, int g, int b, int a) {
  int32_t rgba =
      ((r & 0xFF) << 24) + ((g & 0xFF) << 16) + ((b & 0xFF) << 8) + (a & 0xFF);
  return rgba;
}

static int p5_green(int32_t rgba) { return ((rgba >> 16) & 0xFF); }

static int32_t p5_lerpColor(int32_t ca, int32_t cb, float t) {

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

static int p5_red(int32_t rgba) { return ((rgba >> 24) & 0xFF); }

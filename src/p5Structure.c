#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "p5Structure.h"

static void p5_exit() {
  done = true;
}

static void p5_loop() {
  loop = true;
}

static void p5_noLoop() {
  loop = false;
}

static void p5_popStyle() {
  Context* tmp = ctx;
  ctx = ctx->next;
  
  vgSetParameterfv(fillPaint, VG_PAINT_COLOR, 4, &(ctx->fillColor));
  vgSetParameterfv(strokePaint, VG_PAINT_COLOR, 4, &(ctx->strokeColor));
  
  vgSetf(VG_STROKE_LINE_WIDTH, ctx->strokeWeight);
  vgSeti(VG_STROKE_CAP_STYLE, ctx->strokeCap);
  vgSeti(VG_STROKE_JOIN_STYLE, ctx->strokeJoin);
  vgSetf(VG_STROKE_MITER_LIMIT, ctx->strokeMiter);
  free(tmp);
}

static void p5_pushStyle() {
  Context* tmp;
  tmp = malloc(sizeof(Context));
  memset(tmp,0,sizeof(Context));
  
  tmp->fillColor = vgGetColor(fillPaint);
  tmp->strokeColor = vgGetColor(strokePaint);
  tmp->strokeWeight = vgGetf(VG_STROKE_LINE_WIDTH);
  tmp->strokeCap = vgGeti(VG_STROKE_CAP_STYLE);
  tmp->strokeJoin = vgGeti(VG_STROKE_JOIN_STYLE);
  tmp->strokeMiter = vgGetf(VG_STROKE_MITER_LIMIT);
  tmp->next = ctx;
  ctx = tmp;
}

static void p5_redraw() {
}

static double p5_time() {
  struct timeval tv;
  double t;
  gettimeofday(&tv,NULL);
  t = (tv.tv_sec*1000)+(tv.tv_usec/1000);
  return t;
}
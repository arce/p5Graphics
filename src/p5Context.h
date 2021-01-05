#ifndef P5CONTEXT_H

#include <stdbool.h>
#include <VG/openvg.h>

#define MAX_CONTEXT 10

typedef struct Context {
  float fillColor;
  float strokeColor;
	bool fillEnable;
	bool strokeEnable;
  float strokeWeight;
  int strokeCap;
  int strokeJoin;
  float strokeMiter;
  struct Context *next;
} Context;

extern struct Context *ctx[MAX_CONTEXT];
extern struct Context *curr;

extern VGPaint strokePaint;
extern VGPaint fillPaint;

#endif
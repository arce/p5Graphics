#ifndef P5STYLE_H

#include <stdbool.h>
#include <stdint.h>
#include <VG/openvg.h>

#define MAX_CONTEXT 10

#define P5_NONE -1
#define P5_PIE 0
#define P5_CHORD 1
#define P5_OPEN 2
#define P5_CORNERS 3
#define P5_CENTER 4
#define P5_RADIUS 5
#define P5_CORNER 6
#define P5_MODEL 7
#define P5_SHAPE 8
#define P5_CLOSE VG_CLOSE_PATH

#define P5_LEFT 10
#define P5_RIGHT 11
#define P5_TOP 12
#define P5_BOTTOM 13
#define P5_CHORD 14
#define P5_PIE 15
#define P5_SQUARE VG_CAP_BUTT
#define P5_PROJECT VG_CAP_SQUARE
#define P5_ROUND VG_JOIN_ROUND
#define P5_MITER VG_JOIN_MITER
#define P5_BEVEL VG_JOIN_BEVEL
#define P5_BASELINE 17
#define P5_MIDDLE 18
#define P5_HORIZONTAL 19
#define P5_VERTICAL 20

typedef struct Style {
  int32_t fillColor;
  int32_t strokeColor;
	VGPaintMode fillEnable;
	VGPaintMode strokeEnable;
  float strokeWeight;
  int strokeCap;
  int strokeJoin;
  float strokeMiter;
	int rectMode;
	int ellipseMode;
	int shapeMode;
	int imageMode;
	int textMode;
  struct Style *next;
} Style;

#endif
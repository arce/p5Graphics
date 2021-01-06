#include <stdbool.h>
#include <stdint.h>
#include <VG/openvg.h>
#include <VG/vgu.h>
#include <stdlib.h>

struct Style *curr;

VGPaint strokePaint;
VGPaint fillPaint;

bool done;
bool loop;

void p5_exit();

void p5_loop();

void p5_noLoop();

void p5_popStyle();

void p5_pushStyle();

void p5_redraw();

double p5_time();

extern float backup[9];

extern int _frameCount;

extern int _frameRate;

extern int _height;

extern int _width;

void p5_mainLoop();

void p5_setupFunc(void (*func)());

void p5_drawFunc(void (*func)());

int p5_init(int w, int h);

int p5_frameCount();

int p5_frameRate(int rate);

void p5_fullScreen();

int p5_height();

void p5_noSmooth();

void p5_size(int width, int height);

void p5_smooth();

int p5_width();

void p5_background(int32_t rgba);

void p5_fill(int32_t rgba);

void p5_noFill();

void p5_noStroke();

void p5_stroke(int32_t rgba);

int p5_alpha(int32_t rgba);

int p5_blue(int32_t rgba);

int32_t p5_color(int r, int g, int b, int a);

int p5_green(int32_t rgba);

int32_t p5_lerpColor(int32_t ca, int32_t cb, float t);

int p5_red(int32_t rgba);

#define P5_PIE 0
#define P5_CHORD 1
#define P5_OPEN 2
#define P5_CORNERS 3
#define P5_CENTER 4
#define P5_RADIUS 5
#define P5_CORNER 6

#define P5_POINTS 1
#define P5_POLYLINE 2
#define P5_LINES 3
#define P5_TRIANGLES 4
#define P5_QUADS 5

int pathSize;
int kindShape;
int pathCount;

float s_backup[9];

VGPath arc_path = VG_INVALID_HANDLE;
VGPath ellipse_path = VG_INVALID_HANDLE;
VGPath line_path = VG_INVALID_HANDLE;
VGPath point_path = VG_INVALID_HANDLE;
VGPath quad_path = VG_INVALID_HANDLE;
VGPath rect_path = VG_INVALID_HANDLE;
VGPath triangle_path = VG_INVALID_HANDLE;
VGPath bezier_path = VG_INVALID_HANDLE;
VGPath curve_path = VG_INVALID_HANDLE;

VGPath shape_path = VG_INVALID_HANDLE;
VGPath shape_paths[100] = {VG_INVALID_HANDLE};

void p5_arc(float x, float y, float a, float start, float stop, int type);

void p5_circle(float x, float y, float a);

void p5_ellipse(float x, float y, float a, float b);

void p5_line(float x, float y, float a, float b);

void p5_point(float x, float y);

void p5_quad(float x, float y, float a, float b, float c, float d, float e,
             float f);

void p5_rect(float x, float y, float a, float b);

void p5_square(float x, float y, float a);

void p5_triangle(float x, float y, float a, float b, float c, float d);

void p5_bezier(float x, float y, float a, float b, float c, float d, float e,
               float f);

void p5_curve(float x, float y, float a, float b, float c, float d);

// Attributes:
// ellipseMode()
// rectMode()
// strokeCap()
// strokeJoin()
// strokeWeight()
// strokeMiter()

void p5_ellipseMode(int mode);

void p5_rectMode(int mode);

void p5_strokeCap(int cap);

void p5_strokeJoin(int join);

void p5_strokeWeight(float weight);

void p5_strokeMiter(float miter);

// Vertex commands:
// beginContour() -- todo
// beginShape()
// bezierVertex()
// curveVertex() -- todo
// endShape()
// quadraticVertex()
// vertex()

void p5_beginShape(int kind);

void p5_bezierVertex(float x, float y, float a, float b, float c, float d);

void p5_curveVertex();

void p5_endShape(int mode);

void p5_quadraticVertex(float x, float y, float w, float h);

void p5_vertex(int x, int y);

// Loading & Displaying:
// saveShape() - Diököl extension
// shape()
// shapeMode()

int p5_saveShape(int seg);

void p5_shape(int pid, int w, int h);

void p5_shapeMode(int shapeMode);

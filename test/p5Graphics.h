#include <stdint.h>
#include <stdbool.h>

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
#define P5_CLOSE 9

#define P5_LEFT 10
#define P5_RIGHT 11
#define P5_TOP 12
#define P5_BOTTOM 13
#define P5_SQUARE 16
#define P5_PROJECT 17
#define P5_ROUND 18
#define P5_MITER 19
#define P5_BEVEL 20
#define P5_BASELINE 17
#define P5_MIDDLE 18
#define P5_HORIZONTAL 19
#define P5_VERTICAL 20

#define P5_BACKSPACE 100
#define P5_TAB 101
#define P5_ENTER 102
#define P5_RETURN 103
#define P5_ESC 104
#define P5_DELETE 105

#define MOUSE_MOVED 0
#define MOUSE_DRAGGED 1
#define MOUSE_PRESSED 2
#define MOUSE_RELEASED 3
#define MOUSE_CLICKED 4
#define KEY_PRESSED 5
#define KEY_RELEASED 6
#define WINDOW_RESIZED 7

void p5_exit();

void p5_loop();

void p5_noLoop();

void p5_popStyle();

void p5_pushStyle();

void p5_redraw();

double p5_time();

void p5_mainLoop();

void p5_setupFunc(void (*func)());

void p5_drawFunc(void (*func)());

void p5_resizeFunc(void (*func)(int w, int h));

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

#define P5_POINTS 1
#define P5_POLYLINE 2
#define P5_LINES 3
#define P5_TRIANGLES 4
#define P5_QUADS 5

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

void p5_ellipseMode(int mode);

void p5_rectMode(int mode);

void p5_strokeCap(int cap);

void p5_strokeJoin(int join);

void p5_strokeWeight(float weight);

void p5_strokeMiter(float miter);

void p5_beginShape(int kind);

void p5_bezierVertex(float x, float y, float a, float b, float c, float d);

void p5_curveVertex();

void p5_endShape(int mode);

void p5_quadraticVertex(float x, float y, float w, float h);

void p5_vertex(int x, int y);

int p5_saveShape(int seg);

void p5_shape(int pid, int w, int h);

void p5_shapeMode(int shapeMode);

// p5Input.h


int p5_mouseX();

int p5_mouseY();

int p5_pmouseX();

int p5_pmouseY();

int p5_mouseButton();

bool p5_isMousePressed();

void p5_mouseEvent(int button,int state,int xpos, int ypos);

void p5_motionEvent(int xpos, int ypos);

void p5_passiveMotionEvent(int xpos, int ypos);

void p5_keyPressedEvent(char key, int code);

void p5_keyReleasedEvent(char key, int code);

int p5_isKeyPressed();

int p5_key();

int p5_keyCode();

// Transform:
// applyMatrix()
// popMatrix()
// printMatrix()
// pushMatrix()
// resetMatrix()
// rotate()
// rotateX()
// rotateY()
// rotateZ()
// scale()
// shearX()
// shearY()
// translate()

void p5_popMatrix();

void p5_printMatrix();

void p5_pushMatrix();

void p5_resetMatrix();

void p5_rotate(float angle);

void p5_scale(int sx, int sy);

void p5_shearX(float angle);

void p5_shearY(float angle);

void p5_translate(float dx, float dy);
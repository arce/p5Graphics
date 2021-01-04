// Structure:
// exit()
// loop()
// noLoop()
// redraw()
// setTitle() -- todo
// time() -- Diököl extension

#include <VG/openvg.h>
#include <stdbool.h>

VGPaint strokePaint;
VGPaint fillPaint;

bool done;
bool loop;
	
typedef struct Context {
  VGfloat fillColor;
  VGfloat strokeColor;
  float strokeWeight;
  int strokeCap;
  int strokeJoin;
  float strokeMiter;
  struct Context *next;
} Context;

struct Context *ctx = NULL;

static void p5_exit();

static void p5_loop();

static void p5_noLoop();

static void p5_popStyle();

static void p5_pushStyle();

static void p5_redraw();

static double p5_time();
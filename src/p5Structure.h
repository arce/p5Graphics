// Structure:
// exit()
// loop()
// noLoop()
// redraw()
// setTitle() -- todo
// time() -- Diököl extension

#ifndef P5STRUCTURE_H

#include "p5Context.h"
#include <stdbool.h>

struct Context *curr;

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

#endif
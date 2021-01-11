// Structure:
// exit()
// loop()
// noLoop()
// redraw()
// setTitle() -- todo
// time() -- Diököl extension

#ifndef P5STRUCTURE_H

#include "p5Style.h"
#include <stdbool.h>

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

int _frameCount;

int _frameRate;

int _height;

int _width;

void p5_mainLoop();

void p5_setupFunc(void (*func)());

void p5_drawFunc(void (*func)());

void p5_sizeFunc(void (*func)(int w,int h));

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
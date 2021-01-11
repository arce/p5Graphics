/*
 --
 -- p5Color.h
 --
 -- p5 Graphics Library
 --
 -- Copyright (c) 2021 Armando Arce - arce@itcr.ac.cr
 --
 -- This library is free software; you can redistribute it and/or modify
 -- it under the terms of the MIT license. See LICENSE for details.
 --
 */

#ifndef P5COLOR_H

#include "p5Style.h"
#include <stdint.h>

extern VGPaint strokePaint;
extern VGPaint fillPaint;

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

#endif

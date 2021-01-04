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

#include <stdint.h>
#include <VG/openvg.h>

int32_t fillColor;
int32_t strokeColor;

VGbitfield strokeEnable=0;
VGbitfield fillEnable=0;

VGPaint strokePaint;
VGPaint fillPaint;

/**
* The p5_background() function sets the color used for the background of
* the display window. The default background is light gray. This function is 
* typically used within p5_draw() to clear the display window at the beginning 
* of each frame, but it can be used inside p5_setup() to set the background on 
* the first frame of animation or if the backgound need only be set once.
 */
static void p5_background(int32_t rgba);

static void p5_fill(int32_t rgba);

static void p5_noFill();

static void p5_noStroke();

static void p5_stroke(int32_t rgba);

static int p5_alpha(int32_t rgba);

static int p5_blue(int32_t rgba);

static int32_t p5_color(int r, int g, int b, int a);

static int p5_green(int32_t rgba);

static int32_t p5_lerpColor(int32_t ca, int32_t cb, float t);

static int p5_red(int32_t rgba);

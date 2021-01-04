/*
 --
 -- p5Environment.h
 --
 -- Döiköl Interactive Graphics Environment
 --
 -- Copyright (c) 2017-2020 Armando Arce - armando.arce@gmail.com
 --
 -- This library is free software; you can redistribute it and/or modify
 -- it under the terms of the MIT license. See LICENSE for details.
 --
 */

int _frameCount;
int _frameRate;
int _height;
int _width;
int _smooth;

// Environment:
// frameCount()
// frameRate()
// fullScreen()
// height()
// noSmooth()
// size()
// smooth()
// width()

static int p5_frameCount();

static int p5_frameRate(int rate);

static void p5_fullScreen();

static int p5_height();

static void p5_noSmooth();

static void p5_size(int width, int height);

static void p5_smooth();

static int p5_width();
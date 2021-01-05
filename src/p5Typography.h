/*
 --
 -- p5Typography.h
 --
 -- Döiköl Interactive Graphics Environment
 --
 -- Copyright (c) 2017-2020 Armando Arce - armando.arce@gmail.com
 --
 -- This library is free software; you can redistribute it and/or modify
 -- it under the terms of the MIT license. See LICENSE for details.
 --
 */

// Typography:
// PFont
//
// Loading & Displaying:
// createFont()
// loadFont()
// text()
// textFont

// Typography Attributes commands
// textAlign()
// textLeading()
// textSize()
// textWidth()

#ifndef P5TYPOGRAPHY_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "shFont.h"

#define P5_LEFT 0
#define P5_RIGHT 1
#define P5_CENTER 2
#define P5_BASELINE 3

 int fontId = 0;
 char ttf_buffer[1 << 24];
 int alignX = P5_LEFT;
 int alignY = P5_BASELINE;
 int textLeading;
 int fontCount = 1;
 VGFont fonts[100];
 int fHeight[100];
 int fSize[100];

 char mainPath[256];

 int p5_createFont(char *filename, int textHeight);

 int p5_loadFont(char *filename, int textHeight);

 void p5_text(char *str, int x, int y);

 void p5_textFont(int id);

 void p5_textAlign(int xalig, int yalig);

 void p5_textLeading(int textLead);

 void p5_textSize(int id);

 int p5_textWidth(char *str);

#endif
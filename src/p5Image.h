/*
 --
 -- p5Image.h
 --
 -- p5Graphics:
 --
 -- Copyright (c) 2017-2020 Armando Arce - armando.arce@gmail.com
 --
 -- This library is free software; you can redistribute it and/or modify
 -- it under the terms of the MIT license. See LICENSE for details.
 --
 */

#include <stdint.h>

// Image commands:
// createImage()

#define MAX_IMAGES 100

#define P5_CENTER 0
#define P5_CORNERS 1

int imageCount=0;
int iWidth[MAX_IMAGES];
int iHeight[MAX_IMAGES];
uint8_t** images[MAX_IMAGES];

int _imageMode;

static int p5_createImage(int width,int height);

// Image Loading & Displaying commands:
// imageWidth() -- Diököl extension
// imageHeight() -- Diököl extension
// image()
// imageMode()
// loadImage()
// noTint()
// requestImage()
// tint()

static int p5_imageWidth(int imageId);

static int p5_imageHeight(int imageId);

static void p5_image(int imageId, int x, int y, int w, int h);

static void p5_imageMode(int imageMode);

static int p5_importImage(uint8_t *buffer, int len);

static int p5_loadImage(char* filename);

// Image Pixels commands:
// blend()
// copy()
// filter()
// get()
// loadPixels()
// pixels[]
// set()
// updatePixels()

static void p5_loadPixels(int imageId);

static void p5_updatePixels(int imageId, uint8_t** parray);

// Rendering commands:
// clip()
// noClip()

static void p5_clip(int x, int y, int w, int h);

static void p5_noClip();
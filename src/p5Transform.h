/*
 --
 -- p5Transform.h
 --
 -- Döiköl Interactive Graphics Environment
 --
 -- Copyright (c) 2017-2020 Armando Arce - armando.arce@gmail.com
 --
 -- This library is free software; you can redistribute it and/or modify
 -- it under the terms of the MIT license. See LICENSE for details.
 --
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <VG/openvg.h>

VGfloat backup[9];

typedef struct Matrix {
  VGfloat data[9];
  struct Matrix *next;
} Matrix;

struct Matrix *mtrx_stack = NULL;

Matrix *mtrx_new() {
  Matrix *mtrx;
  mtrx = malloc(sizeof(Matrix));
  memset(mtrx,0,sizeof(Matrix));
  mtrx->next = NULL;
  return mtrx;
}

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

//static void p5_applyMatrix();

static void p5_popMatrix();

static void p5_printMatrix();

static void p5_pushMatrix();

static void p5_resetMatrix();

static void p5_rotate(float angle);

static void p5_scale(int sx, int sy);

static void p5_shearX(float angle);

static void p5_shearY(float angle);

static void p5_translate(float dx, float dy);
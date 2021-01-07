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
#ifndef P5TRANSFORM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Matrix {
  float data[9];
  struct Matrix *next;
} Matrix;

 struct Matrix *mtrx_stack = NULL;

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

// void p5_applyMatrix();

 void p5_popMatrix();

 void p5_printMatrix();

 void p5_pushMatrix();

 void p5_resetMatrix();

 void p5_rotate(float angle);

 void p5_scale(int sx, int sy);

 void p5_shearX(float angle);

 void p5_shearY(float angle);

 void p5_translate(float dx, float dy);

#endif
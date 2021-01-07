/*
 --
 -- p5Shapes.h
 --
 -- p5 Graphics Library
 --
 -- Copyright (c) 2021 Armando Arce - arce@itcr.ac.cr
 --
 -- This library is free software; you can redistribute it and/or modify
 -- it under the terms of the MIT license. See LICENSE for details.
 --
 */

// 2D Primitives:
// arc()
// circle()
// ellipse()
// line ()
// point()
// quad()
// rect()
// square()
// triangle()
// bezier()
// quad()

#ifndef P5SHAPES_H

#include <stdlib.h>
#include <stdbool.h>

#define P5_POINTS 1
#define P5_POLYLINE 2
#define P5_LINES 3
#define P5_TRIANGLES 4
#define P5_QUADS 5

extern struct Style *curr;

void p5_arc(float x, float y, float a, float start, float stop, int type);

void p5_circle(float x, float y, float a);

void p5_ellipse(float x, float y, float a, float b);

void p5_line(float x, float y, float a, float b);

void p5_point(float x, float y);

void p5_quad(float x, float y, float a, float b, float c, float d, float e,
             float f);

void p5_rect(float x, float y, float a, float b);

void p5_square(float x, float y, float a);

void p5_triangle(float x, float y, float a, float b, float c, float d);

void p5_bezier(float x, float y, float a, float b, float c, float d, float e,
               float f);

void p5_curve(float x, float y, float a, float b, float c, float d);

// Attributes:
// ellipseMode()
// rectMode()
// strokeCap()
// strokeJoin()
// strokeWeight()
// strokeMiter()

void p5_ellipseMode(int mode);

void p5_rectMode(int mode);

void p5_strokeCap(int cap);

void p5_strokeJoin(int join);

void p5_strokeWeight(float weight);

void p5_strokeMiter(float miter);

// Vertex commands:
// beginContour() -- todo
// beginShape()
// bezierVertex()
// curveVertex() -- todo
// endShape()
// quadraticVertex()
// vertex()

void p5_beginShape(int kind);

void p5_bezierVertex(float x, float y, float a, float b, float c, float d);

void p5_curveVertex();

void p5_endShape(int mode);

void p5_quadraticVertex(float x, float y, float w, float h);

void p5_vertex(int x, int y);

// Loading & Displaying:
// saveShape() - Diököl extension
// shape()
// shapeMode()

int p5_saveShape(int seg);

void p5_shape(int pid, int w, int h);

void p5_shapeMode(int shapeMode);

#endif
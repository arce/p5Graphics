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

#include <stdlib.h>
#include <VG/openvg.h>
#include <VG/vgu.h>

#define P5_PIE 0
#define P5_CHORD 1
#define P5_OPEN 2
#define P5_CORNERS 3
#define P5_CENTER 4
#define P5_RADIUS 5
#define P5_CORNER 6

#define P5_POINTS 1
#define P5_POLYLINE 2
#define P5_LINES 3
#define P5_TRIANGLES 4
#define P5_QUADS 5

int ellipseMode;
int rectMode;
int shapeMode;

int fillEnable;
int strokeEnable;

int pathSize;
int kindShape;
int pathCount;

static VGPath arc_path = VG_INVALID_HANDLE;
static VGPath ellipse_path = VG_INVALID_HANDLE;
static VGPath line_path = VG_INVALID_HANDLE;
static VGPath point_path = VG_INVALID_HANDLE;
static VGPath quad_path = VG_INVALID_HANDLE;
static VGPath rect_path = VG_INVALID_HANDLE;
static VGPath triangle_path = VG_INVALID_HANDLE;
static VGPath bezier_path = VG_INVALID_HANDLE;
static VGPath curve_path = VG_INVALID_HANDLE;

static VGPath shape_path = VG_INVALID_HANDLE;
static VGPath shape_paths[100] = {VG_INVALID_HANDLE};

static void p5_arc(float x, float y, float a, float start, float stop,
                   int type);

static void p5_circle(float x, float y, float a);

static void p5_ellipse(float x, float y, float a, float b);

void p5_line(float x, float y, float a, float b);

static void p5_point(float x, float y);

static void p5_quad(float x, float y, float a, float b, float c, float d,
                    float e, float f);

static void p5_rect(float x, float y, float a, float b);

static void p5_square(float x, float y, float a);

static void p5_triangle(float x, float y, float a, float b, float c, float d);

static void p5_bezier(float x, float y, float a, float b, float c, float d,
                      float e, float f);

static void p5_curve(float x, float y, float a, float b, float c, float d);

// Attributes:
// ellipseMode()
// rectMode()
// strokeCap()
// strokeJoin()
// strokeWeight()
// strokeMiter()

static void p5_ellipseMode(int mode);

static void p5_rectMode(int mode);

static void p5_strokeCap(int cap);

static void p5_strokeJoin(int join);

static void p5_strokeWeight(float weight);

static void p5_strokeMiter(float miter);

// Vertex commands:
// beginContour() -- todo
// beginShape()
// bezierVertex()
// curveVertex() -- todo
// endShape()
// quadraticVertex()
// vertex()

static void p5_beginShape(int kind);

static void p5_bezierVertex(float x, float y, float a, float b, float c,
                            float d);

static void p5_curveVertex();

static void p5_endShape(int mode);

static void p5_quadraticVertex(float x, float y, float w, float h);

static void p5_vertex(int x, int y);

// Loading & Displaying:
// saveShape() - Diököl extension
// shape()
// shapeMode()

static int p5_saveShape(int seg);

static void p5_shape(int pid, int w, int h);

static void p5_shapeMode(int shapeMode);
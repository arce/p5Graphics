/*
 --
 -- p5Math.h
 --
 -- Döiköl Interactive Graphics Environment
 --
 -- Copyright (c) 2017-2020 Armando Arce - armando.arce@gmail.com
 --
 -- This library is free software; you can redistribute it and/or modify
 -- it under the terms of the MIT license. See LICENSE for details.
 --
 */

// Math:
//
// Calculation functions:
// constrain()
// dist()
// lerp()
// mag()
// map()
// norm()

#ifndef M_PI
#    define M_PI 3.14159265358979323846f
#endif
#define _deg(angleRadians) (angleRadians * 180.0 / M_PI)
#define _rad(angleDegrees) (angleDegrees / 180.0 * M_PI)

#define P5_PI 3.14159265358979323846f
#define P5_TWO_PI 6.28318530718f
#define P5_HALF_PI 1.57079632679f
#define P5_QUARTER_PI 0.78539816339f

static float p5_constrain(float amt, float low, float high);

static float p5_dist(float x1, float y1,float x2,float y2);

static float P5_lerp(float a,float b,float f);

static float p5_mag(float x, float y);

static float p5_map(float value,float start1,float stop1,float start2,float stop2);

static float p5_norm(float value,float start1,float stop1);

// Trigonometry functions:
// degrees()
// radians()

static float p5_degrees(float radians);

static float p5_radians(float degrees);
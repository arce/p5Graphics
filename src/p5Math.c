#include "p5Math.h"
#include <math.h>

static float p5_constrain(float amt, float low, float high) {
  float value;
  if (amt < low)
    value = low;
  else if (amt > high)
    value = high;
  else
    value = amt;
  return value;
}

static float p5_dist(float x1, float y1,float x2,float y2) {
#ifdef __linux__
  float d = STBTT_sqrt(STBTT_pow(x2-x1,2)+STBTT_pow(y2-y1,2));
#else
  float d = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
#endif
	return d;
}

static float P5_lerp(float a,float b,float f) {
  float l = a + f * (b - a);
  return l;
}

static float p5_mag(float x, float y) {
#ifdef __linux__
  float d = STBTT_sqrt(STBTT_pow(x,2)+STBTT_pow(y,2));
#else
  float d = sqrt(pow(x,2)+pow(y,2));
#endif
  return d;
}

static float p5_map(float value,float start1,float stop1,float start2,float stop2) {
  float outgoing =
  start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
  return outgoing;
}

static float p5_norm(float value,float start1,float stop1) {
  float outgoing = ((value - start1) / (stop1 - start1));
  return outgoing;
}

static float p5_degrees(float radians) {
  float degrees;
  degrees = _deg(radians);
  return degrees;
}

static float p5_radians(float degrees) {
  float radians;
  radians = _rad(degrees);
  return radians;
}
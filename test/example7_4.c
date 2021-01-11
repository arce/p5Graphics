#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 7-4: Using a function that returns a value, distance

void setup() {
  p5_size(480, 270);
}

float dist(float x1, float y1, float x2, float y2) {
  float dx = x1 - x2;
  float dy = y1 - y2;
  float d = sqrt(dx*dx + dy*dy);
  return d;
}

void draw() {
  p5_background(255);
  p5_stroke(0);

  float d = dist(p5_width()/2, p5_height()/2, p5_mouseX(), p5_mouseY());
  p5_fill(p5_color(d*3, d*2, d, 255));
  p5_ellipseMode(P5_CENTER);
  p5_ellipse(p5_width()/2, p5_height()/2, 100, 100);
}
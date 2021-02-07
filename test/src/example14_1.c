#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 14-1: A growing rectangle, or a rectangle moving toward you?

float r = 8;

void setup() {
  p5_size(200, 200);
  p5_frameRate(10);
}

void draw() {
  p5_background(255);

  // Display a rectangle in the middle of the screen
  p5_stroke(0);
  p5_fill(175);
  p5_rectMode(P5_CENTER);
  p5_rect(p5_width()/2, p5_height()/2, r, r);

  // Increase the rectangle size
  r++ ;

  // Start rectangle over
  if (r > p5_width()) {
	r = 0;
  }
}

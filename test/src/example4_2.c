#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 4-2: Using variables

// Declare and initialize two integer variables at the top of the code.
int circleX = 100;
int circleY = 100;

void setup() {
  p5_size(480, 270);
}

void draw() {
  p5_background(255);
  p5_stroke(0);
  p5_fill(175);
  // Use the variables to specify the location of an ellipse.
  p5_ellipse(circleX,circleY,50,50);
}
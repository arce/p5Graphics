#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 4-3: Varying variables

// Declare and initialize two integer variables at the top of the code.
int circleX = 0;
int circleY = 100;

void setup() {
  p5_size(480, 270);
  p5_frameRate(10);
  p5_loop();
}

void draw() {
  p5_background(255);
  p5_stroke(0);
  p5_fill(175);
  // Use the variables to specify the location of an ellipse.
  p5_ellipse(circleX, circleY, 50, 50);

  // An assignment operation that increments the value of circleX by 1.
  circleX = circleX + 1;
}
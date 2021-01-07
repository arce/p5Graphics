#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 1-3: RGB Color

void setup() {}

void draw() {

  p5_background(255);
  p5_noStroke();

  // Bright red
  p5_fill(p5_color(255, 0, 0, 255));
  p5_ellipse(20, 20, 16, 16);

  // Dark red
  p5_fill(p5_color(127, 0, 0, 255));
  p5_ellipse(40, 20, 16, 16);

  // Pink (pale red)
  p5_fill(p5_color(255, 200, 200, 255));
  p5_ellipse(60, 20, 16, 16);
}
#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 5-7: "Bouncing" color

// Two variables for color.
float c1 = 0;
float c2 = 255;

// Start by incrementing c1.
float c1Change = 1;
// Start by decrementing c2.
float c2Change = -1;

void setup() { p5_size(480, 270); }

void draw() {
  p5_noStroke();

  // Draw rectangle on left
  p5_fill(p5_color(c1, 0, c2,255));
  p5_rect(0, 0, 320, 360);

  // Draw rectangle of right
  p5_fill(p5_color(c2, 0, c1,255));
  p5_rect(320, 0, 320, 360);

  // Adjust color values
  c1 = c1 + c1Change;
  c2 = c2 + c2Change;

  // Instead of reaching the edge of a window, these variables reach the "edge"
  // of color: 0 for no color and 255 for full color. When this happens, just
  // like with the bouncing ball, the change is reversep5_

  // Reverse direction of color change
  if (c1 < 0 || c1 > 255) {
    c1Change *= -1;
  }

  if (c2 < 0 || c2 > 255) {
    c2Change *= -1;
  }
}
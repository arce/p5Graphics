#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 1-4: Alpha Transparency

void setup() { p5_size(480, 270); }

void draw() {

  p5_background(0);
  p5_noStroke();

  // No fourth argument means 100% opacity.
  p5_fill(p5_color(0, 0, 255, 255));
  p5_rect(0, 0, 240, 200);

  // 255 means 100% opacity.
  p5_fill(p5_color(255, 0, 0, 255));
  p5_rect(0, 0, 480, 40);

  // 75% opacity.
  p5_fill(p5_color(255, 0, 0, 191));
  p5_rect(0, 50, 480, 40);

  // 55% opacity.
  p5_fill(p5_color(255, 0, 0, 127));
  p5_rect(0, 100, 480, 40);

  // 25% opacity.
  p5_fill(p5_color(255, 0, 0, 63));
  p5_rect(0, 150, 480, 40);
}
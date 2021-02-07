#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 3-7: Translated zoog

void setup() {
  p5_size(480, 270);
}

void draw() {
  p5_background(255);
  p5_rectMode(P5_CENTER);
  p5_ellipseMode(P5_CENTER);

  // Draw everything relative to (mouseX, mouseY)
  p5_translate(p5_mouseX(), p5_mouseY());

  // Draw Zoog's body
  p5_stroke(0);
  p5_fill(175);
  p5_rect(0, 0, 20, 100);

  // Draw Zoog's head
  p5_stroke(0);
  p5_fill(255);
  p5_ellipse(0, -30, 60, 60);

  // Draw Zoog's eyes
  p5_stroke(0);
  p5_fill(0);
  p5_ellipse(-19, -30, 16, 32);
  p5_ellipse( 19, -30, 16, 32);

  // Draw Zoog's legs
  p5_stroke(0);
  p5_line(-10, 50, -20, 60);
  p5_line( 10, 50, 20, 60);
}
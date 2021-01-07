#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 5-9: Simple Gravity

float x = 320;   // x location of square
float y = 0;     // y location of square

float speed = 0;   // speed of square

// A new variable, for gravity (i.e. acceleration).   
// We use a relatively small number (0.1) because this accelerations accumulates over time, increasing the speep5_   
// Try changing this number to 2.0 and see what happens.
float gravity = 0.1;

void setup() {
  p5_size(480, 270);
}

void draw() {
  p5_background(255);

  // Display the square
  p5_fill(175);
  p5_stroke(0);
  p5_rectMode(P5_CENTER);
  p5_rect(x, y, 10, 10);

  // Add speed to location.
  y = y + speed;

  // Add gravity to speep5_
  speed = speed + gravity;

  // If square reaches the bottom
  // Reverse speed
  if (y > p5_height()) {
    // Multiplying by -0.95 instead of -1 slows the square down each time it bounces (by decreasing speed).  
    // This is known as a "dampening" effect and is a more realistic simulation of the real world (without it, a ball would bounce forever).
    speed = speed * -0.95;
    y = p5_height();
  }
}
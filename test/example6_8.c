#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 6-8: Lines one at a time

int y = 0;

void setup() {
  p5_size(480, 270);
  p5_background(255);
  // Slowing down the frame rate so we can easily see the effect.
  p5_frameRate(5); 
}

void draw() {
  // Draw a line
  p5_stroke(0);
  // Only one line is drawn each time through draw().
  p5_line(0,y,width,y); 
  // Increment y
  y += 10;
  
  // Reset y back to 0 when it gets to the bottom of window
  if (y > height) {
    y = 0;
  }
}
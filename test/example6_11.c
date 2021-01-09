#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 6-11: Multiple Zoogs

int w = 60;
int h = 60;
int eyeSize = 16;

void setup() {
  p5_size(480, 270);
}

void draw() {
  p5_background(255);

  p5_ellipseMode(CENTER);
  p5_rectMode(CENTER);

  int y = p5_height()/2;

  // Multiple versions of Zoog
  // The variable x is now included in a for loop, 
  // in order to iterate and display multiple Zoogs!
  for (int x = 80; x < p5_width(); x += 80) { 

    // Draw Zoog's body
    p5_stroke(0);
    p5_fill(175);
    p5_rect(x, y, w/6, h*2);

    // Draw Zoog's head
    p5_fill(255);
    p5_ellipse(x, y-h/2, w, h);

    // Draw Zoog's eyes
    p5_fill(0);
    p5_ellipse(x-w/3, y-h/2, eyeSize, eyeSize*2);
    p5_ellipse(x+w/3, y-h/2, eyeSize, eyeSize*2);

    // Draw Zoog's legs
    p5_stroke(0);
    p5_line(x-w/12, y+h, x-w/4, y+h+10);
    p5_line(x+w/12, y+h, x+w/4, y+h+10);
  }
}
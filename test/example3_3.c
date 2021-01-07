#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 3-3: Zoog as dynamic sketch with variation

void setup() {
  p5_size(480, 270);  // Set the size of the window
}

void draw() {
  p5_background(255);  // Draw a white background 

  // Set ellipses and rects to CENTER mode
  p5_ellipseMode(P5_CENTER);
  p5_rectMode(P5_CENTER); 

  // Draw Zoog's body
  p5_stroke(0);
  p5_fill(175);
  // Zoog's body is drawn at the location (mouseX, mouseY).
  p5_rect(p5_mouseX(), p5_mouseY(), 20, 100);

  // Draw Zoog's head
  p5_stroke(0);
  p5_fill(255);
  // Zoog's head is drawn above the body at the location (mouseX, mouseY - 30).
  p5_ellipse(p5_mouseX(), p5_mouseY()-30, 60, 60); 

  // Eyes
  p5_fill(0); 
  p5_ellipse(221, 115, 16, 32); 
  p5_ellipse(259, 115, 16, 32);

  // Legs
  p5_stroke(0);
  p5_line(230, 195, 220, 205);
  p5_line(250, 195, 260, 205);
}
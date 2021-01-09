#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 7-5: Zoog with functions

float x = 240;
float y = 180;
float w = 60;
float h = 60;
float eyeSize = 16;

void setup() {
  p5_size(480, 270);
}

void jiggleZoog(float speed) {
  // Change the x and y location of Zoog randomly
  x = x + random(-1, 1)*speed;
  y = y + random(-1, 1)*speed;
  // Constrain Zoog to window
  x = constrain(x, 0, p5_width());
  y = constrain(y, 0, p5_height());
}

void drawZoog(color eyeColor) {
  // Set ellipses and rects to CENTER mode
  p5_ellipseMode(CENTER);
  p5_rectMode(CENTER);
  // Draw Zoog's arms with a for loop
  for (float i = y - h/3; i < y + h/2; i += 10) {
    p5_stroke(0);
    p5_line(x - w/4, i, x + w/4, i);
  }
  // Draw Zoog's body
  p5_stroke(0);
  p5_fill(175);
  p5_rect(x, y, w/6, h);
  // Draw Zoog's head
  p5_stroke(0);
  p5_fill(255);
  p5_ellipse(x, y - h, w, h);
  // Draw Zoog's eyes
  p5_fill(eyeColor);
  p5_ellipse(x - w/3, y - h, eyeSize, eyeSize*2);
  p5_ellipse(x + w/3, y - h, eyeSize, eyeSize*2);
  // Draw Zoog's legs
  p5_stroke(0);
  p5_line(x - w/12, y + h/2, x - w/4, y + h/2 + 10);
  p5_line(x + w/12, y + h/2, x + w/4, y + h/2 + 10);
}

void draw() {
  p5_background(255); // Draw a white background

  // A color based on distance from the mouse
  float d = dist(x, y, p5_mouseX(), p5_mouseY());
  color c = color(d);

  // mouseX position determines speed factor for moveZoog function
  float factor = p5_constrain(p5_mouseX()/10, 0, 5);

  // The code for changing the variables associated 
  // with Zoog and displaying Zoog is moved 
  // outside of draw() and into functions called here. 
  // The functions are given arguments, such 
  // as "Jiggle Zoog by the following factor"
  // and "draw Zoog with the following eye color."
  jiggleZoog(factor);
  drawZoog(c);
}
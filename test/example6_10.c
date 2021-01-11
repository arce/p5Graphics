#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 6-10: Zoog with arms

int x = 100;
int y = 100;
int w = 60;
int h = 60;
int eyeSize = 16;
int speed = 1;

void setup() {
  p5_size(480, 270);
}

void draw() {
  // Change the x location of Zoog by speed
  x = x + speed;

  // If we've reached an edge, reverse speed (i.e. multiply it by -1)
  //(Note if speed is a + number, square moves to the right,- to the left)
  if ((x > p5_width()) || (x < 0)) {
    speed = speed * -1;
  }

  p5_background(255); // Draw a white background

  // Set ellipses and rects to CENTER mode
  p5_ellipseMode(P5_CENTER);
  p5_rectMode(P5_CENTER);

  // Arms are incorporated into Zoog's design with a for loop. 
  for (int i = y + 5; i < y + h; i += 10) { 
    p5_stroke(0);
    p5_line(x-w/3,i,x + w/3,i);
  }
  
  // Draw Zoog's body
  p5_stroke(0);
  p5_fill(175);
  p5_rect(x,y,w/6,h*2);
  
  // Draw Zoog's head
  p5_fill(255);
  p5_ellipse(x,y-h/2,w,h);
  
  // Draw Zoog's eyes
  p5_fill(0);
  p5_ellipse(x-w/3+1,y-h/2,eyeSize,eyeSize*2);
  p5_ellipse(x+w/3-1,y-h/2,eyeSize,eyeSize*2);
  
  // Draw Zoog's legs
  p5_stroke(0);
  p5_line(x-w/12,y + h,x-w/4,y + h + 10);
  p5_line(x+w/12,y + h,x + w/4,y + h + 10);
}

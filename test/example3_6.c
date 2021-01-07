#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 3-6: Interactive Zoog?

void setup() {
  // Set the size of the window
  p5_size(480, 270);  
  // The frame rate is set to 30 frames per second.
  p5_frameRate(30);
}

void draw() {
  // Draw a white background
  p5_background(255);  

  // Set ellipses and rects to CENTER mode
  p5_ellipseMode(P5_CENTER);
  p5_rectMode(P5_CENTER); 

  // Draw Zoog's body
  p5_stroke(0);
  p5_fill(175);
  p5_rect(p5_mouseX(), p5_mouseY(), 20, 100);

  // Draw Zoog's head
  p5_stroke(0);
  p5_fill(255);
  p5_ellipse(p5_mouseX(), p5_mouseY()-30, 60, 60); 

  // Draw Zoog's eyes
  // The eye color is determined by the mouse location.
  p5_fill(p5_color(p5_mouseX()/2, 0, p5_mouseY()/2,255)); 
  p5_ellipse(p5_mouseX()-19, p5_mouseY()-30, 16, 32); 
  p5_ellipse(p5_mouseX()+19, p5_mouseY()-30, 16, 32); 

  // Draw Zoog's legs
  p5_stroke(0);
  // The legs are drawn according to the mouse location and the previous mouse location.
  p5_line(p5_mouseX()-10, p5_mouseY()+50, p5_pmouseX()-10, p5_pmouseY()+60);
  p5_line(p5_mouseX()+10, p5_mouseY()+50, p5_pmouseX()+10, p5_pmouseY()+60);
}

void mousePressed() {
  printf("Take me to your leader!\n"); 
}
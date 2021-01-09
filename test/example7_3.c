#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 7-3: Bouncing ball with functions

// Declare all global variables (stays the same)
int x = 0;
int speed = 1;

// Setup does not change
void setup() {
  p5_size(480, 270);
}

// Where should functions be placed?
// You can define your functions anywhere in the code 
// outside of setup() and draw(). However, the convention 
// is to place your function definitions below draw().

// A function to move the ball
void move() { 
  // Change the x location by speed
  x = x + speed;
}

// A function to bounce the ball
void bounce() {
  // If we’ve reached an edge, reverse speed
  if ((x > p5_width()) || (x < 0)) {
    speed = speed * - 1;
  }
}

// A function to display the ball
void display() {
  p5_stroke(0);
  p5_fill(175);
  p5_ellipse(x, p5_height()/2, 32, 32);
}

void draw() {
  p5_background(255);
  // Instead of writing out all the code about the ball is draw(), I 
  // simply call three functions. How do I know the names of these 
  // functions? I made them up!
  move(); 
  bounce();
  display();
}
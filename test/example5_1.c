#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 5-1: Conditionals

// Variables
float r = 150;
float g = 0;
float b = 0;

void setup() {
  p5_size(480, 270);
}

void draw() {
  // Draw stuff
  p5_background(r,g,b);  
  p5_stroke(255);
  p5_line(p5_width()/2,0,p5_width()/2,p5_height());

  // If the mouse is on the right side of the screen is equivalent to 
  // "if mouseX is greater than width divided by 2."
  if(p5_mouseX > p5_width()/2) {
    r = r + 1; 
  } else {
    r = r - 1;
  }

  // If r is greater than 255, set it back to 255.  
  // If r is less than 0, set it back to 0.
  if (r > 255) {
    r = 255; 
  } else if (r < 0) {
    r = 0; 
  }
}

int main(int argc, char** argv) {
  p5_drawFunc(draw);
  setup();
  
  p5_listen();
}
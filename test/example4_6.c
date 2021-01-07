#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 4-6: Ellipse with variables

// Declare and initialize your variables!
float r = 100;
float g = 150;
float b = 200;
float a = 200;
  
float diam = 20;
float x = 100;
float y = 100;

void setup() {
  p5_size(480, 270);
  p5_background(255);
}

void draw() {
  // Use those variables to draw an ellipse
  p5_stroke(0);
  p5_fill(r,g,b,a);  // (Remember, the fourth argument for a color is transparency.
  p5_ellipse(x,y,diam,diam);  
}
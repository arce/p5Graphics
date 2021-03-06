#include "p5lib.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 4-7: Filling variables with random values

float r;
float g;
float b;
float a;

float diam;
float x;
float y;

void setup() {
  p5_size(480, 270);
  p5_background(255);
  p5_frameRate(10);    
}

void draw() {
  // Each time through draw(), new random numbers are picked for a new ellipse.
  r = p5_random(255);
  g = p5_random(255);
  b = p5_random(255);
  a = p5_random(255);
  diam = p5_random(20);
  x = p5_random(p5_width);
  y = p5_random(p5_height);
  
  // Use values to draw an ellipse
  p5_noStroke();
  p5_fillRGBA(r,g,b,a);
  p5_ellipse(x,y,diam,diam);
}

int main(int argc, char** argv) {
  p5_setupFunc(setup);
  p5_drawFunc(draw);
  p5_init(argc,argv);
}
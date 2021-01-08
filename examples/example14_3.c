#include "p5lib.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 14-3: A rectangle moving along the z-axis

// A variable for the Z (depth) coordinate

float z = 0;

void setup() {
  p5_size(200, 200);
  p5_frameRate(10);
}

void draw() {
  p5_background(255);
  p5_stroke(0);
  p5_fill(175);

  // Translate to a point before displaying a shape there
  //p5_translate3d(p5_width/2, p5_height/2, z);
  p5_rectMode(P5_CENTER);
  p5_rect(0, 0, 8, 8); 

  // Increment z (i.e. move the shape toward the viewer)
  z += 2;

  // Restart rectangle
  if (z > 200) {
    z = 0;
  }
}

int main(int argc, char** argv) {
  p5_setupFunc(setup);
  p5_drawFunc(draw);
  p5_init(argc,argv);
}

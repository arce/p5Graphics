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

// The function sets the vertices for the pyramid around the centerpoint at a flexible distance, 
// depending on the number passed in as an argument.
void drawPyramid(int t) { 

  p5_stroke(0);

  // this pyramid has 4 sides, each drawn as a separate triangle
  // each side has 3 vertices, making up a triangle shape
  // the parameter " t " determines the size of the pyramid
  p5_beginShape(P5_TRIANGLES);

  p5_fillA(255, 150); // Note that each polygon can have its own color.
  //p5_vertex3d(-t, -t, -t);
  //p5_vertex3d( t, -t, -t);
  //p5_vertex3d( 0, 0, t);

  p5_fillA(150, 150);
  //p5_vertex3d( t, -t, -t);
  //p5_vertex3d( t, t, -t);
  //p5_vertex3d( 0, 0, t);

  p5_fillA(255, 150);
  //p5_vertex3d( t, t, -t);
  //p5_vertex3d(-t, t, -t);
  //p5_vertex3d( 0, 0, t);

  p5_fillA(150, 150);
  //p5_vertex3d(-t, t, -t);
  //p5_vertex3d(-t, -t, -t);
  //p5_vertex3d( 0, 0, t);

  p5_endShape();
}

void draw() {
  p5_background(255);

  // The pyramid's vertices are drawn relative to a centerpoint.
  // Therefore, we call translate() to place the pyramid properly in the window.
  // A slightly better option might be to include the translate in the drawPyramid() function and pass in x,y,z as arguments
  //p5_translate3d(100, 100, 0); 
  drawPyramid(150);
}

int main(int argc, char** argv) {
  p5_setupFunc(setup);
  p5_drawFunc(draw);
  p5_init(argc,argv);
}

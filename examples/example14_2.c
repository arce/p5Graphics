#include "p5lib.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 14-2: Multiple translations

void setup() {
  p5_size(200, 200);
  p5_frameRate(10);
}

void draw() {
  p5_background(255);
  p5_stroke(0);
  p5_fill(175);

  // Grab mouse coordinates, constrained to window
  int mx = p5_constrain(p5_mouseX, 0, p5_width);
  int my = p5_constrain(p5_mouseY, 0, p5_height);

  // Translate to the mouse location
  p5_translate(mx, my);
  p5_ellipse(0, 0, 8, 8);

  // Translate 100 pixels to the right
  p5_translate(100, 0);
  p5_ellipse(0, 0, 8, 8);

  // Translate 100 pixels down
  p5_translate(0, 100);
  p5_ellipse(0, 0, 8, 8);

  // Translate 100 pixels left
  p5_translate(-100, 0);
  p5_ellipse(0, 0, 8, 8);
}

int main(int argc, char** argv) {
  p5_setupFunc(setup);
  p5_drawFunc(draw);
  p5_init(argc,argv);
}

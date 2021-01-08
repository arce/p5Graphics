#include "p5lib.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 3-4: Drawing a continuous line
void setup() {
  p5_size(480, 270);
  p5_background(255);
}

void draw() {
  p5_stroke(0);
  // Draw a line from previous mouse location to current mouse location.
  p5_line(p5_pmouseX, p5_pmouseY, p5_mouseX, p5_mouseY);
}

int main(int argc, char** argv) {
  p5_setupFunc(setup);
  p5_drawFunc(draw);
  p5_init(argc,argv);
}
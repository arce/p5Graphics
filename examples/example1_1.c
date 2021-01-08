#include "p5lib.h"

  // Learning Processing
  // Daniel Shiffman
  // http://www.learningprocessing.com

  // Example 1-1: stroke and fill

void setup() {
  p5_size(480,270);
}

void draw() {
  p5_background(255);
  p5_stroke(0); 
  p5_fill(150);
  p5_rect(50,50,75,100);
}

int main(int argc, char** argv) {
  p5_setupFunc(setup);
  p5_drawFunc(draw);
  p5_init(argc,argv);
}
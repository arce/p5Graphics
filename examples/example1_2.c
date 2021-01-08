#include "p5lib.h"

	// Learning Processing
	// Daniel Shiffman
	// http://www.learningprocessing.com

	// Example 1-2: noFill

void setup() {
  p5_size(480,270);
}

void draw() {
	p5_background(255);

	// noFill() leaves the shape with only an outline.
	p5_noFill();
	p5_stroke(0);
	p5_ellipse(60,60,100,100);
}

int main(int argc, char** argv) {
  p5_setupFunc(setup);
  p5_drawFunc(draw);
  p5_init(argc,argv);
}
#include "p5lib.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 14-5: Rectangle rotating around center

void setup() {
  p5_size(200, 200);
  p5_frameRate(10);
}

void draw() {
	p5_background(255);  
	p5_stroke(0);
	p5_fill(175);

	// Translate origin to center
	p5_translate(p5_width/2, p5_height/2);

	// The greek letter, theta, is often used as the name of a variable to store an angle
	// The angle ranges from 0 to TWO_PI using the map() function
	float theta = p5_map(p5_mouseX, 0, p5_width, 0, P5_TWO_PI); 

	// Rotate by the angle theta
	p5_rotate(theta);

	// Display rectangle with CENTER mode
	p5_rectMode(P5_CENTER);
	p5_rect(0, 0, 100, 100);
}

int main(int argc, char** argv) {
  p5_setupFunc(setup);
  p5_drawFunc(draw);
  p5_init(argc,argv);
}

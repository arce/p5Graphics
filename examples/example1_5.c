#include "p5lib.h"

	// Learning Processing
	// Daniel Shiffman
	// http://www.learningprocessing.com

	// Example 1-5: Zoog

void setup() {
  p5_size(480, 270);
}

void draw() {
	p5_background(255);
	p5_smooth();
	p5_ellipseMode(P5_CENTER);
	p5_rectMode(P5_CENTER); 

	// Body
	p5_stroke(0);
	p5_fill(150);
	p5_rect(240, 145, 20, 100);

	// Head
	p5_fill(255);
	p5_ellipse(240, 115, 60, 60); 

	// Eyes
	p5_fill(0); 
	p5_ellipse(221, 115, 16, 32); 
	p5_ellipse(259, 115, 16, 32);

	// Legs
	p5_stroke(0);
	p5_line(230, 195, 220, 205);
	p5_line(250, 195, 260, 205);
}

int main(int argc, char** argv) {
    p5_setupFunc(setup);
    p5_drawFunc(draw);
    p5_init(argc,argv);
}
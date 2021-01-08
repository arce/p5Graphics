#include "p5lib.h"

	// Learning Processing
	// Daniel Shiffman
	// http://www.learningprocessing.com

	// Example 1-4: Alpha Transparency

void setup() {
	p5_size(480, 270);
}

void draw() {
	p5_background(0);
	p5_noStroke();

	// No fourth argument means 100% opacity.
	p5_fillRGB(0,0,255);
	p5_rect(0, 0, 240, 200);

	// 255 means 100% opacity.
	p5_fillRGBA(255,0,0,255);
	p5_rect(0, 0, 480, 40);

	// 75% opacity.
	p5_fillRGBA(255,0,0,191);
	p5_rect(0, 50, 480, 40);

	// 55% opacity.
	p5_fillRGBA(255,0,0,127);
	p5_rect(0, 100, 480, 40);

	// 25% opacity.
	p5_fillRGBA(255,0,0,63);
	p5_rect(0, 150, 480, 40);
}

int main(int argc, char** argv) {
    p5_setupFunc(setup);
    p5_drawFunc(draw);
    p5_init(argc,argv);
}
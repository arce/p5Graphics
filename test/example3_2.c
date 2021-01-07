#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 3-2: mouseX and mouseY

void setup() {
	p5_size(480, 270);
}

void draw() {
	// Try moving background() to setup() and see the difference!
	p5_background(255);

	// Body
	p5_stroke(0);
	p5_fill(175);
	p5_rectMode(P5_CENTER);

	// mouseX is a keyword that the sketch replaces with the horizontal position of the mouse.
	// mouseY is a keyword that the sketch replaces with the vertical position of the mouse.
	p5_rect(p5_mouseX(),p5_mouseY(), 50, 50);
}
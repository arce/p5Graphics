#include "p5lib.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 4-8: Variable Zoog

// NEW FEATURE #1: Zoog will rise from below the screen 
// and fly off into space (above the screen.)

// NEW FEATURE #2: Zoog's eyes will be colored randomly as Zoog moves.

// Declaring Variables.  
// zoogX and zoogY are for feature #1.  
// eyeR, eyeG, eyeB are for feature #2.
float zoogX;
float zoogY;

float eyeR;
float eyeG;
float eyeB;

void setup() {
  // Set the size of the window
  p5_size(480, 270);        
  // Feature #1.  zoogX and zoogY are initialized 
  // based on the size of the window.  Note we cannot 
  // initialize these variables before the size() 
  // function is called since we are using the built-in 
  // variables width and height.
  zoogX = p5_width/2;      // Zoog always starts in the middle
  zoogY = p5_height + 100; // Zoog starts below the screen
  p5_frameRate(10); 
}

void draw() {

	p5_background(255);  // Draw a white background 

	// Set ellipses and rects to CENTER mode
	p5_ellipseMode(P5_CENTER);
	p5_rectMode(P5_CENTER); 

	// Draw Zoog's body
	p5_stroke(0);
	p5_fill(150);
	// Feature #1.  zoogX and zoogY are used for the shape locations.
	p5_rect(zoogX, zoogY, 20, 100);

	// Draw Zoog's head
	p5_stroke(0);
	p5_fill(255);
	p5_ellipse(zoogX, zoogY-30, 60, 60); 

	// Draw Zoog's eyes
	// Feature #2.  eyeR, eyeG, and eyeB are given 
	// random values and used in the fill() function.
	eyeR = p5_random(255);
	eyeG = p5_random(255);
	eyeB = p5_random(255);
	p5_fillRGB(eyeR, eyeG, eyeB);

	p5_ellipse(zoogX-19, zoogY-30, 16, 32); 
	p5_ellipse(zoogX+19, zoogY-30, 16, 32); 

	// Draw Zoog's legs
	p5_stroke(150);
	p5_line(zoogX-10, zoogY+50, zoogX-10, p5_height);
	p5_line(zoogX+10, zoogY+50, zoogX+10, p5_height);

	// Zoog moves up
	zoogY = zoogY - 1;
}

int main(int argc, char** argv) {
  p5_setupFunc(setup);
  p5_drawFunc(draw);
  p5_init(argc,argv);
}
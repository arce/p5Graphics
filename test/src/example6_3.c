#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 6-1: Many lines 

void setup() {
  p5_size(480,270);
}

void draw() {
	p5_background(255);

	int y = 80;       // Vertical location of each line
	int x = 50;       // Initial horizontal location for first line
	int spacing = 10; // How far apart is each line
	int len = 20;     // Length of each line

	// A variable to mark where the legs end.
	int endLegs = 150; 
	p5_stroke(0);

	// Draw each leg inside a while loop.
	while (x <= endLegs) { 
	  p5_line (x, y, x, y + len);
	  x = x + spacing;
	}
}

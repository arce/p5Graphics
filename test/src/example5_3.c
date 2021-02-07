#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 5-3: Rollovers

void setup() {
  p5_size(480, 270);
}

void draw() {
	p5_background(255);
	p5_stroke(0);
	p5_line(320,0,320,360);
	p5_line(0,180,640,180);

	// Fill a black color
	p5_noStroke();
	p5_fill(0);

	// Depending on the mouse location, a different rectangle is displayed.    
	if (p5_mouseX() < 320 && p5_mouseY() < 180) {
	  p5_rect(0,0,320,180);
	} else if (p5_mouseX() > 320 && p5_mouseY() < 180) {
	  p5_rect(320,0,320,180);
	} else if (p5_mouseX() < 320 && p5_mouseY() > 180) {
	  p5_rect(0,180,320,180);
	} else if (p5_mouseX() > 320 && p5_mouseY() > 180) {
	  p5_rect(320,180,320,180);
	}
}

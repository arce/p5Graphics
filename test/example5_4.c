#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 5-4: Hold down the button

bool button = false;

int x = 50;
int y = 50;
int w = 100;
int h = 75;

void setup() {
  p5_size(480, 270); 
}

void draw() {
	// The button is pressed if (mouseX,mouseY) is inside the rectangle and mousePressed is true.
	if (p5_mouseX() > x && p5_mouseX() < x+w && p5_mouseY() > y && p5_mouseY() < y+h && p5_isMousePressed()) {
	  button = true; 
	} else {
	  button = false;
	}

	if (button) {
	  p5_background(255);
	  p5_stroke(0);
	} else {
	  p5_background(0);
	  p5_stroke(255);
	}

	p5_fill(175);
	p5_rect(x,y,w,h);
}

#include "p5lib.h"
#include <stdbool.h>

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 5-5: Button as switch
bool button = false;

int x = 50;
int y = 50;
int w = 100;
int h = 75;

void setup() {
  p5_size(480,270);
}

void draw() {
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

void mousePressed() {
  if (p5_mouseX > x && p5_mouseX < x+w && p5_mouseY > y && p5_mouseY < y+h) {
    button = !button;
  }  
}

int main(int argc, char** argv) {
  p5_setupFunc(setup);
  p5_drawFunc(draw);
  p5_mousePressedFunc(mousePressed);
  p5_init(argc,argv);
}

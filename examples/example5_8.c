#include "p5lib.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 5-8: Square following edge, uses a "state" variable

int x = 0;  // x location of square
int y = 0;  // y location of square

int speed = 5;  // speed of square

// A variable to keep track of the square's "state".  
// Depending on the value of its state, it will either move right, down, left, or up.
int state = 0; 

void setup() {
  p5_size(480,270);
}

void draw() {
  p5_background(255);

  // Display the square
  p5_stroke(0);
  p5_fill(175);
  p5_rect(x,y,9,9);

  // If the state is 0, move to the right.
  if (state == 0) {
    x = x + speed;
    // If, while the state is 0, it reaches the right side of the window, change the state to 1
    // Repeat this same logic for all states!?
    if (x > p5_width-10) {
      x = p5_width-10;
      state = 1;
    }
  } else if (state == 1) {
    y = y + speed;
    if (y > p5_height-10) {
      y = p5_height-10;
      state = 2;
    }
  } else if (state == 2) {
    x = x - speed;
    if (x < 0) {
      x = 0;
      state = 3;
    }
  } else if (state == 3) {
    y = y - speed;
    if (y < 0) {
      y = 0;
      state=0;
    }
  }
}

int main(int argc, char** argv) {
  p5_setupFunc(setup);
  p5_drawFunc(draw);
  p5_init(argc,argv);
}

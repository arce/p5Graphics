#include "p5lib.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 4-5: Using system variables
void setup() {
  p5_size(480, 270);
  p5_frameRate(10);
}

void draw() {
  p5_background(100);
  p5_stroke(255);
  // frameCount is used to color a rectangle.
  p5_fill(p5_frameCount / 2);
  p5_rectMode(P5_CENTER);
  // The rectangle will always be in the middle of the window 
  // if it is located at (width/2, height/2).
  p5_rect(p5_width/2,p5_height/2,p5_mouseX+10,p5_mouseY+10);
}

void keyPressed() {
  p5_println(p5_key);
}

int main(int argc, char** argv) {
  p5_setupFunc(setup);
  p5_drawFunc(draw);
  p5_keyPressedFunc(keyPressed);
  p5_init(argc,argv);
}
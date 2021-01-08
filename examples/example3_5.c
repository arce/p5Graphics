#include "p5lib.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 3-5: mousePressed and keyPressed
void setup() {
  p5_size(480, 270);
  p5_background(255);
}

void draw() {
 // Nothing happens in draw() in this example!
}

// Whenever a user clicks the mouse the code written inside mousePressed() is executed.
void mousePressed() {
  p5_stroke(0);
  p5_fill(175);
  p5_rectMode(P5_CENTER);
  p5_rect(p5_mouseX,p5_mouseY,16,16);
}

// Whenever a user presses a key the code written inside keyPressed() is executed.
void keyPressed() {
  p5_background(255);
}

int main(int argc, char** argv) {
  p5_mousePressedFunc(mousePressed);
  p5_keyPressedFunc(keyPressed);
  p5_setupFunc(setup);
  p5_drawFunc(draw);
  p5_init(argc,argv);
}
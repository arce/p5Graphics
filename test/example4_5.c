#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 4-5: Using system variables

void setup() {
  p5_size(480, 270);
}

void draw() {
  p5_background(50);
  p5_stroke(255);
  // frameCount is used to color a rectangle.
  p5_fill(pg.frameCount / 2);
  p5_rectMode(pg.CENTER);
  // The rectangle will always be in the middle of the window 
  // if it is located at (width/2, height/2).
  p5_rect(pg.width/2, pg.height/2, pg.mouseX+10, pg.mouseY+10);
}

void keyPressed() {
  printf("%d\n",p5_key());
}

int main(int argc, char** argv) {  
	pg5_keyPressedFunc(keyPressed);
}
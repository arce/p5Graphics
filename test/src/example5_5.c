#include <p5Graphics.h>
#include "glfw_window.h"


// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 5-5: Button as switch

bool button = false;

int x = 50;
int y = 50;
int w = 100;
int h = 75;

void mousePressed() {
  if (p5_mouseX() > x && p5_mouseX() < x + w && p5_mouseY() > y &&
      p5_mouseY() < y + h) {
    button = !button;
  }
}

void setup() { 
  p5_size(480, 270); 
  p5_mousePressedFunc(&mousePressed);
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
  p5_rect(x, y, w, h);
}

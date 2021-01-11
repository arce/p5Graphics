#include <p5Graphics.h>
#include "glfw_window.h"
#include "math.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 6-9: Simple while with interactivity

void setup() {
  p5_size(480, 270);
}

void draw() {
  p5_background(0);

  // Start with i as 0
  int i = 0;

  // While i is less than the width of the window
  while (i < p5_width()) {
    p5_noStroke();
    // The distance between the current rectangle 
    // and the mouse is equal to the absolute value 
    // of the difference between i and mouseX.
    float dist = abs(p5_mouseX() - i); 
    
    // That distance is used to fill the color of 
    // a rectangle at horizontal location i.
    p5_fill(dist);
    p5_rect(i, 0, 10, p5_height());
    // Increase i by 10
    i += 10;
  }
}

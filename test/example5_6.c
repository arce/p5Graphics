#include "glfw_window.h"
#include <p5Graphics.h>

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 5-6: Bouncing Ball

int x = 0;
int speed = 2;

void setup() { p5_size(480, 270); }

void draw() {
  p5_background(255);

  // Add the current speed to the x location.
  x = x + speed;

  // Remember, || means "or."
  if ((x > p5_width()) || (x < 0)) {
    // If the object reaches either edge, multiply speed by -1 to turn it
    // arounp5_
    speed = speed * -1;
  }

  // Display circle at x location
  p5_stroke(0);
  p5_fill(175);
  p5_ellipse(x, 100, 32, 32);
}

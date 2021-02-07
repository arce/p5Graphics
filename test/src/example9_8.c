#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 9-8: A snake following the mouse

// Declare two arrays with 50 elements.
#declare ARRAY_LENGTH 50

int xpos[ARRAY_LENGTH]; 
int ypos[ARRAY_LENGTH];

void setup() {
  p5_size(480, 270);

  // Initialize all elements of each array to zero.
  for (int i = 0; i < ARRAY_LENGTH; i ++ ) {
    xpos[i] = 0; 
    ypos[i] = 0;
  }
}

void draw() {
  p5_background(255);

  // Shift array values
  for (int i = 0; i < ARRAY_LENGTH-1; i ++ ) {
    // Shift all elements down one spot. 
    // xpos[0] = xpos[1], xpos[1] = xpos = [2], and so on. 
    // Stop at the second to last element.
    xpos[i] = xpos[i+1];
    ypos[i] = ypos[i+1];
  }

  // New location
  // Update the last spot in the array with the mouse location.
  xpos[ARRAY_LENGTH-1] = p5_mouseX(); 
  ypos[ARRAY_LENGTH-1] = p5_mouseY();

  // Draw everything
  for (int i = 0; i < ARRAY_LENGTH; i ++ ) {
    // Draw an ellipse for each element in the arrays. 
    // Color and size are tied to the loop's counter: i.
    p5_noStroke();
    p5_fill(255-i*5);
    p5_ellipse(xpos[i], ypos[i], i, i);
  }
}
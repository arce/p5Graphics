#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 17-1: Simple displaying text

// Step 2: Declare PFont variable

PFont f;  

void setup() {
  p5_size(480, 270);

  // Step 3: Create Font
  f = p5_createFont("Georgia.ttf", 32);
} 

void draw() {
	p5_background(255);

  p5_textFont(f); // Step 4: Specify font to be used
  p5_fill(0);         // Step 5: Specify font color

  // Step 6: Display Text
  p5_text("Mmmmm ... Strings ...", 10, p5_height()/2);
}
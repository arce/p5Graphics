#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 17-5: Rotating text 

PFont f;
char message[] = "this text is spinning";
float theta;

void setup() {
  p5_size(480, 270);
  f = p5_createFont("Georgia.ttf", 20);
}

void draw() {

  p5_background(255);
  p5_fill(0);
  p5_textFont(f);                  // Set the font
  p5_textAlign(P5_CENTER,P5_CENTER);
  p5_pushMatrix();
  p5_translate(p5_width()/2, p5_height()/2); // Translate to the center
  p5_rotate(theta);                // Rotate by theta

  // The text is center aligned and displayed at (0,0) after translating and rotating. 
  // See Chapter 14 or a review of translation and rotation.
  p5_text(message, 0, 0); 
  p5_popMatrix();

  // Increase rotation
  theta += 0.02;
}
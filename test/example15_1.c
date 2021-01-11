#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 15-1: "Hello World" images

// Declaring a variable of type PImage
// PImage is a class available from the Processing core library.
PImage img; 

void setup() {
  p5_size(320, 240);
  // Make a new instance of a PImage by loading an image file
  img = p5_loadImage("runde_bird_cliffs.jpg");
}

void draw() {
  p5_background(0);
  // The image() function displays the image at a location
  // in this case the point (0,0).
  p5_image(img, 0, 0, p5_width(), p5_height());
}

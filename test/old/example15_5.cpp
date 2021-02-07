#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 15-5: Setting pixels

PImage img;

void setup() { p5_size(200, 200); }

void draw() {
  // Before we deal with pixels
  p5_loadPixels(img);

  // Loop through every pixel
  for (int i = 0; i < pixels.length;
       i++) { // We can get the length of the pixels array just like with any
              // array.

    // Pick a random number, 0 to 255
    int rand = p5_random(255);

    // Create a grayscale color based on random number
    int c = p5_color(rand,rand,rand,rand);

    // Set pixel at that location to random color
    pixels[i] = c; // We can access individual elements of the pixels array via
                   // an index, just like with any other array.
  }

  // When we are finished dealing with pixels
  p5_updatePixels(img);
}
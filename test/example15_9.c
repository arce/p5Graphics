#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

PImage img;

void setup() {
  size(200, 200);
  img = p5_loadImage( "sunflower.jpg" );
}

void draw() {
  p5_loadPixels();
  img.loadPixels();

  // We must also call loadPixels() on the PImage since we are going to read its pixels.  img.loadPixels(); 
  for (int x = 0; x < img.width; x++ ) {
    for (int y = 0; y < img.height; y++ ) {

      // Calculate the 1D pixel location
      int loc = x + y*img.width;

      // Get the R,G,B values from image
      float r = p5_red  (img.pixels[loc]);
      float g = p5_green(img.pixels[loc]);
      float b = p5_blue (img.pixels[loc]);

      // Calculate an amount to change brightness
      // based on proximity to the mouse
      float distance = p5_dist(x, y, mouseX, mouseY);

      // The closer the pixel is to the mouse, the lower the value of "distance" 
      // We want closer pixels to be brighter, however, so we invert the value using map()
      // Pixels with a distance of 50 (or greater) have a brightness of 0.0 (or negative which is equivalent to 0 here)
      // Pixels with a distance of 0 have a brightness of 1.0.
      float adjustBrightness = p5_map(distance, 0, 50, 8, 0);
      r *= adjustBrightness;
      g *= adjustBrightness;
      b *= adjustBrightness;

      // Constrain RGB to between 0-255
      r = p5_constrain(r, 0, 255);
      g = p5_constrain(g, 0, 255);
      b = p5_constrain(b, 0, 255);

      // Make a new color and set pixel in the window
      color c = p5_color(r, g, b);
      pixels[loc] = c;
    }
  }

  p5_updatePixels();
}
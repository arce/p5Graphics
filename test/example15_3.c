#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 15-3: Swapping images

#define maxImages 10 // Total # of images
int imageIndex = 0; // Initial image to be displayed is the first

// Declaring an array of images.
PImage images[maxImages]; 
char filename[12];

void setup() {
  p5_size(200, 200);

  // Loading the images into the array
  // Don't forget to put the JPG files in the data folder!
  for (int i = 0; i < maxImages; i ++ ) {
		sprintf(filename, "animal%d.jpg", i);
    images[i] = p5_loadImage(filename);
  }
}

void draw() {
  // Displaying one image
  p5_image(images[imageIndex], 0, 0, 0,0);
}

void mousePressed() {
  // A new image is picked randomly when the mouse is clicked
  // Note the index to the array must be an integer!
  imageIndex = (int)p5_random(maxImages);
}
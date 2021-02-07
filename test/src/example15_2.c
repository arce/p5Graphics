#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 15-2: Image "sprite"

int head; // A variable for the image file
float x,y;   // Variables for image location
float rot;   // A variable for image rotation

void setup() {
  p5_size(200,200);
  
  // Load image, initialize variables
  head = p5_loadImage("face.jpg");
  x = 0.0;
  y = p5_width()/2.0;
  rot = 0.0;
}

void draw() {
  p5_background(255);
  
  // Translate and rotate
  p5_translate(x,y);
  p5_rotate(rot);
  
  // Images can be animated just like regular shapes using variables, translate(), rotate(), and so on.
  p5_imageMode(P5_CENTER);
  p5_image(head,0,0,p5_imageWidth(head),p5_imageHeight(head)); 
  
  // Adjust variables for animation
  x += 1.0;
  rot += 0.02;
  if (x > p5_width()+p5_imageWidth(head)) {
    x = -p5_imageWidth(head);
  }
}

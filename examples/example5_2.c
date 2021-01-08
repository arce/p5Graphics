#include "p5lib.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 5-2: More conditionals

// Three variables for the background color.
float r = 0;
float b = 0;
float g = 0;

void setup() {
  p5_size(480,270);
  p5_frameRate(10);
}

void draw() {
    // Color the background and draw lines to divide the window in quadrants.
    p5_backgroundRGB(r,g,b);  
    p5_stroke(255);
    p5_line(p5_width/2,0,p5_width/2,p5_height);
    p5_line(0,p5_height/2,p5_width,p5_height/2);
  
    // If the mouse is on the right hand side of the window, increase red.  
    // Otherwise, it is on the left hand side and decrease red.
    if (p5_mouseX > p5_width/2) {
      r = r + 1; 
    } else {
      r = r - 1;
    }
  
    // If the mouse is on the bottom of the window, increase blue.  
    // Otherwise, it is on the top and decrease blue.
    if (p5_mouseY > p5_height/2) {
      b = b + 1; 
    } else {
      b = b - 1; 
    }
  
    // If the mouse is pressed (using the system variable mousePressed)
    if (p5_mousePressed) {
      g = g + 1; 
    } else {
      g = g - 1; 
    }  
  
    // Constrain all color values to between 0 and 255.
    r = p5_constrain(r,0,255);
    g = p5_constrain(g,0,255);
    b = p5_constrain(b,0,255);
}

int main(int argc, char** argv) {
  p5_setupFunc(setup);
  p5_drawFunc(draw);
  p5_init(argc,argv);
}

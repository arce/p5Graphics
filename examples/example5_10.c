#include "p5lib.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 5-10: Zoog and conditionals
float x = 100;
float y = 100;
float w = 60;
float h = 60;
float eyeSize = 16;

// Zoog has variables for speed in the horizontal and vertical direction.
float xspeed = 3;
float yspeed = 1;

void setup() {
  p5_size(480,270);
}

void draw() {
    // Change the location of Zoog by speed
    x = x + xspeed;
    y = y + yspeed;

    // An IF statement with a logical OR determines if Zoog has reached either the right or left edge of the screen.  
    // When this is true, we multiply speed by -1, reversing Zoog's direction!
    // Identical logic is applied to the y direction as well.
    if ((x > p5_width) || (x < 0)) {
      xspeed = xspeed * -1;
    }

    if ((y > p5_height) || (y < 0)) {
      yspeed = yspeed * -1;
    }

    p5_background(255);  
    p5_ellipseMode(P5_CENTER);
    p5_rectMode(P5_CENTER); 

    // Draw Zoog's body
    p5_stroke(0);
    p5_fill(150);
    p5_rect(x,y,w/6,h*2);

    // Draw Zoog's head
    p5_fill(255);
    p5_ellipse(x,y-h/2,w,h); 

    // Draw Zoog's eyes
    p5_fill(0); 
    p5_ellipse(x-w/3+1,y-h/2,eyeSize,eyeSize*2); 
    p5_ellipse(x+w/3-1,y-h/2,eyeSize,eyeSize*2);

    // Draw Zoog's legs
    p5_stroke(0);
    p5_line(x-w/12,y+h,x-w/4,y+h+10);
    p5_line(x+w/12,y+h,x+w/4,y+h+10);
}

int main(int argc, char** argv) {
  p5_setupFunc(setup);
  p5_drawFunc(draw);
  p5_init(argc,argv);
}

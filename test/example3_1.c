#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 3-1: Zoog as dynamic sketch

// setup() runs first one time.  
// size() should always be first line of setup

void setup() {
	// Set the size of the window
	p5_size(480, 270);
}

// draw() loops continuously until you close the sketch window.
void draw() {
    // Draw a white background
    p5_background(255);   

    // Set CENTER mode
    p5_ellipseMode(P5_CENTER);
    p5_rectMode(P5_CENTER); 

    // Body
    p5_stroke(0);
    p5_fill(150);
    p5_rect(240, 145, 20, 100);

    // Head
    p5_fill(255);
    p5_ellipse(240, 115, 60, 60); 

    // Eyes
    p5_fill(0); 
    p5_ellipse(221, 115, 16, 32); 
    p5_ellipse(259, 115, 16, 32);

    // Legs
    p5_stroke(0);
    p5_line(230, 195, 220, 205);
    p5_line(250, 195, 260, 205);
}
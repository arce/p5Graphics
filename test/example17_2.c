#include <p5Graphics.h>
#include "glfw_window.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 17-2: Text align

float r = 8;
int width = 480;
int height = 270;

void setup() {
  p5_size(width, height);
  PFont fnt = p5_loadFont("fonts/lucida.txf");
  PImage img = p5_loadImage("icons/laptop130.png");
  PShape shp = p5_createShape(P5_RECT, 0, 0, 80, 80);
  p5_textFont(fnt);
}

void draw() {
  p5_background(255.0f);
  p5_stroke(175.0f);

  p5_line(width / 2, 0, width / 2, height);
  p5_textSize(16);
  p5_fill(0.0f);

  p5_textAlign(P5_CENTER, 0);
  p5_text("This text is centerep5_", width / 2, 160);
  p5_textAlign(P5_LEFT, 0);
  p5_text("This text is left alignep5_", width / 2, 200);
  p5_textAlign(P5_RIGHT, 0);
  p5_text("This text is right alignep5_", width / 2, 240);

  p5_shape(shp, 10, 20);
  p5_image(img, 30, 40);
}

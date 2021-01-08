#include "p5lib.h"

// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 17-2: Text align 

//PFont f; 

float r = 8;

void setup() {
  p5_size(480, 270);

  //f = createFont("Arial", 16);
}

void draw() {
  p5_background(255);
  p5_stroke(175);
  p5_line(p5_width/2, 0, p5_width/2, p5_height);
  //p5_textFont(f);
  p5_textSize(16);
  p5_fill(0);

  // textAlign() sets the alignment for displaying text. It takes one argument: CENTER, LEFT, or RIGHT.
  p5_textAlign(P5_CENTER);
  p5_text("This text is centered.", p5_width/2, 160);
  p5_textAlign (P5_LEFT) ;
  p5_text("This text is left aligned.", p5_width/2, 200);
  p5_textAlign(P5_RIGHT);
  p5_text("This text is right aligned.", p5_width/2, 240);
}

int main(int argc, char** argv) {
  p5_setupFunc(setup);
  p5_drawFunc(draw);
  p5_init(argc,argv);
}

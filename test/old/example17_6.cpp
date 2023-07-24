#include <p5Graphics.h>
#include "glfw_window.h"

// Example 17-6: Text breaking up 

PFont f;
char message[] = "click mouse to shake it up";

// An array of Letter objects
char[] letters;

void setup() {
  p5_size(480, 270);

  // Load the font
  f = p5_createFont("Arial", 20);
  p5_textFont(f);

  // Create the array the same size as the String
  letters = new Letter[message.length()];

  // Initialize Letters at the correct x location
  int x = 125;
  for (int i = 0; i < strlen(message); i ++ ) {
    // Letter objects are initialized with their location within the String as well as what character they should display.
    letters[i] = new Letter(x, 140, message[i]); 
    x += p5_textWidth(message[i]);
  }
}

void draw() {
  background(255);
  for (int i = 0; i < strlen(letters); i ++ ) {

    // Display all letters
    letters[i].display();

    // If the mouse is pressed the letters shake
    // If not, they return to their original location
    if (p5_mousePressed()) {
      letters[i].shake();
    } else {
      letters[i].home();
    }
  }
}
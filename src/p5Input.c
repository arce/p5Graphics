/*
 --
 -- p5Color.h
 --
 -- Döiköl Interactive Graphics Environment
 --
 -- Copyright (c) 2017-2021 Armando Arce - armando.arce@gmail.com
 --
 -- This library is free software; you can redistribute it and/or modify
 -- it under the terms of the MIT license. See LICENSE for details.
 --
 */

#define P5_BACKSPACE 100
#define P5_TAB 101
#define P5_ENTER 102
#define P5_RETURN 103
#define P5_ESC 104
#define P5_DELETE 105

#define P5_LEFT 6
#define P5_RIGHT 7
#define P5_MIDDLE 8

#define MOUSE_MOVED 0
#define MOUSE_DRAGGED 1
#define MOUSE_PRESSED 2
#define MOUSE_RELEASED 3
#define MOUSE_CLICKED 4
#define KEY_PRESSED 5
#define KEY_RELEASED 6
#define WINDOW_RESIZED 7

// Input:
//
// Mouse:
// mouseButton
// mouseClicked()
// mouseDragged()
// mouseMoved()
// mousePressed()
// mousePressed
// mouseReleased()
// mouseWheel()
// mouseX
// mouseY
// pmouseX
// pmouseY
//
// Keyboard:
// key
// keyCode
// keyPressed()
// keyPressed
// keyReleased()
// keyTyped()

#include "p5Input.h"
#include "stdlib.h"

#define MOUSE_MOVED 0
#define MOUSE_DRAGGED 1
#define MOUSE_PRESSED 2
#define MOUSE_RELEASED 3
#define MOUSE_CLICKED 4
#define KEY_PRESSED 5
#define KEY_RELEASED 6
#define WINDOW_RESIZED 7

int mouseButton;
int pmouseX, mouseX, pmouseY, mouseY;
int keyCode;
int eventType;

char keyPress[2] = "X\0";

char *eventArray[] = {"mouseMoved",    "mouseDragged", "mousePressed",
                      "mouseReleased", "mouseClicked", "keyPressed",
                      "keyReleased",   "windowResized"};

bool isEvent[] = {false, false, false, false, false, false, false, false};

bool eventFunc[] = {false, false, false, false, false, false, false, false};

bool event[] = {false, false, false, false, false, false, false, false};

void (*mouseMoved_func)(int x, int y) = NULL;

void (*mouseDragged_func)(int x, int y) = NULL;

void (*mousePressed_func)(int key, int keyCode) = NULL;

void (*mouseReleased_func)(int x, int y) = NULL;

void (*mouseClicked_func)() = NULL;

void (*keyPressed_func)(int key, int keyCode) = NULL;

void (*keyReleased_func)(int key, int keyCode) = NULL;

void (*windowResized_func)(int w, int h) = NULL;

int LEFT_BUTTON, RIGHT_BUTTON, MIDDLE_BUTTON, DOWN;

void p5_mouseMovedFunc(void (*func)(int x, int y)) {
  eventFunc[MOUSE_MOVED] = true;
  mouseMoved_func = func;
}

void p5_mouseDraggedFunc(void (*func)(int x, int y)) {
  eventFunc[MOUSE_DRAGGED] = true;
  mouseDragged_func = func;
}

void p5_mousePressedFunc(void (*func)(int key, int keyCode)) {
  eventFunc[MOUSE_PRESSED] = true;
  mousePressed_func = func;
}

void p5_mouseReleasedFunc(void (*func)(int x, int y)) {
  eventFunc[MOUSE_RELEASED] = true;
  mouseReleased_func = func;
}

void p5_mouseClickedFunc(void (*func)()) {
  eventFunc[MOUSE_CLICKED] = true;
  mouseClicked_func = func;
}

void p5_keyPressedFunc(void (*func)(int key, int keyCode)) {
  eventFunc[KEY_PRESSED] = true;
  keyPressed_func = func;
}

void p5_keyReleasedFunc(void (*func)(int key, int keyCode)) {
  eventFunc[KEY_RELEASED] = true;
  keyReleased_func = func;
}

void p5_windowResizedFunc(void (*func)(int w, int h)) {
  eventFunc[WINDOW_RESIZED] = true;
  windowResized_func = func;
}

int p5_mouseX() { return mouseX; }

int p5_mouseY() { return mouseY; }

int p5_pmouseX() { return pmouseX; }

int p5_pmouseY() { return pmouseY; }

int p5_mouseButton() { return mouseButton; }

bool p5_isMousePressed() { return isEvent[MOUSE_PRESSED]; }

void p5_mouseEvent(int button, int state, int xpos, int ypos) {
  pmouseX = mouseX;
  pmouseY = mouseY;
  mouseX = xpos;
  mouseY = ypos;
  if (button == LEFT_BUTTON) {
    mouseButton = P5_LEFT;
  } else if (button == RIGHT_BUTTON) {
    mouseButton = P5_RIGHT;
  } else {
    mouseButton = P5_MIDDLE;
  }
  if (state == DOWN) {
    eventType = MOUSE_PRESSED;
    isEvent[MOUSE_PRESSED] = true;
  } else {
    eventType = MOUSE_RELEASED;
    isEvent[MOUSE_RELEASED] = true;
  }
}

void p5_motionEvent(int xpos, int ypos) {
  pmouseX = mouseX;
  pmouseY = mouseY;
  mouseX = xpos;
  mouseY = ypos;
  eventType = MOUSE_DRAGGED;
  isEvent[MOUSE_DRAGGED] = true;
}

void p5_passiveMotionEvent(int xpos, int ypos) {
  pmouseX = mouseX;
  pmouseY = mouseY;
  mouseX = xpos;
  mouseY = ypos;
  eventType = MOUSE_MOVED;
  isEvent[MOUSE_DRAGGED] = true;
}

void p5_processEvents() {
  for (int i = 0; i < 8; i++) {
    if (isEvent [i] && eventFunc[i]) {
      switch (i) {
      case MOUSE_MOVED:
        (*mouseMoved_func)(mouseX, mouseY);
        break;
      case MOUSE_DRAGGED:
        (*mouseDragged_func)(mouseX, mouseY);
				 break;
      case MOUSE_PRESSED:
        (*mousePressed_func)(mouseX, mouseY);
				 break;
      case MOUSE_RELEASED:
        (*mouseReleased_func)(mouseX, mouseY);
				 break;
      case MOUSE_CLICKED:
        (*mouseClicked_func)(mouseX, mouseY);
				 break;
      case KEY_PRESSED:
        (*keyPressed_func)(keyPress[0], keyCode);
				 break;
      case KEY_RELEASED:
        (*keyPressed_func)(keyPress[0], keyCode);
				 break;
      case WINDOW_RESIZED:
        (*windowResized_func)(p5_width(), p5_height());
      }
		}
  }
}
// Keyboard:
// key
// keyCode
// keyPressed()
// keyPressed
// keyReleased()
// keyTyped()

void p5_keyPressedEvent(char key, int code) {
  keyPress[0] = key;
  keyCode = code;
  eventType = KEY_PRESSED;
  isEvent[KEY_PRESSED] = true;
}

void p5_keyReleasedEvent(char key, int code) {
  keyCode = code;
  eventType = KEY_RELEASED;
  isEvent[KEY_RELEASED] = true;
}

int p5_isKeyPressed() { return isEvent[KEY_PRESSED]; }

int p5_key() { return keyPress; }

int P5_keyCode() { return keyCode; }
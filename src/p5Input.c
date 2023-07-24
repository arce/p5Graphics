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

#define MOUSE_PRESSED 0
#define KEY_PRESSED 1
#define MOUSE_RELEASED 2
#define MOUSE_MOVED 3
#define MOUSE_DRAGGED 4
#define MOUSE_CLICKED 5
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

int mouseButton, mouseState;
int pmouseX, mouseX, pmouseY, mouseY;
int keyCode, eventType;

char keyPress;

bool isEvent[] = {false, false, false, false, false, false, false, false};

bool eventFunc[] = {false, false, false, false, false, false, false, false};

int p5_width();

int p5_height();

void (*mouseMoved_func)() = NULL;

void (*mouseDragged_func)() = NULL;

void (*mousePressed_func)() = NULL;

void (*mouseReleased_func)() = NULL;

void (*mouseClicked_func)() = NULL;

void (*keyPressed_func)() = NULL;

void (*keyReleased_func)() = NULL;

void (*windowResized_func)(int w, int h) = NULL;

void p5_mouseMovedFunc(void (*func)()) {
  eventFunc[MOUSE_MOVED] = true;
  mouseMoved_func = func;
}

void p5_mouseDraggedFunc(void (*func)()) {
  eventFunc[MOUSE_DRAGGED] = true;
  mouseDragged_func = func;
}

void p5_mousePressedFunc(void (*func)()) {
  eventFunc[MOUSE_PRESSED] = true;
  mousePressed_func = func;
}

void p5_mouseReleasedFunc(void (*func)()) {
  eventFunc[MOUSE_RELEASED] = true;
  mouseReleased_func = func;
}

void p5_mouseClickedFunc(void (*func)()) {
  eventFunc[MOUSE_CLICKED] = true;
  mouseClicked_func = func;
}

void p5_keyPressedFunc(void (*func)()) {
  eventFunc[KEY_PRESSED] = true;
  keyPressed_func = func;
}

void p5_keyReleasedFunc(void (*func)()) {
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

void p5_mouseEvent(int button, int state) {
  mouseButton = button;
  mouseState = state;
  if (mouseState == P5_PRESS)
    isEvent[MOUSE_PRESSED] = true;
  else { 
    isEvent[MOUSE_RELEASED] = true;
    isEvent[MOUSE_CLICKED] = true;
    isEvent[MOUSE_PRESSED] = false;
  }
}

void p5_motionEvent(int xpos, int ypos) {
  pmouseX = mouseX;
  pmouseY = mouseY;
  mouseX = xpos;
  mouseY = ypos;
  if (mouseState == P5_PRESS)
    isEvent[MOUSE_DRAGGED] = true;
  else
    isEvent[MOUSE_MOVED] = true;
}

void p5_cleanEvents() {
  for (int i = 2; i < 8; i++)
    isEvent[i] = false;
}

void p5_processEvents() {
  for (int i = 0; i < 8; i++) {
    if (isEvent[i] && eventFunc[i]) {
      switch (i) {
      case MOUSE_MOVED:
        (*mouseMoved_func)();
        break;
      case MOUSE_DRAGGED:
        (*mouseDragged_func)();
        break;
      case MOUSE_PRESSED:
        (*mousePressed_func)();
        break;
      case MOUSE_RELEASED:
        (*mouseReleased_func)();
        break;
      case MOUSE_CLICKED:
        (*mouseClicked_func)();
        break;
      case KEY_PRESSED:
        (*keyPressed_func)();
        break;
      case KEY_RELEASED:
        (*keyReleased_func)();
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
  keyPress = key;
  keyCode = code;
  eventType = KEY_PRESSED;
  isEvent[KEY_PRESSED] = true;
}

void p5_keyReleasedEvent(char key, int code) {
  keyCode = code;
  eventType = KEY_RELEASED;
  isEvent[KEY_RELEASED] = true;
  isEvent[KEY_PRESSED] = false;
}

int p5_isKeyPressed() { return isEvent[KEY_PRESSED]; }

char p5_key() { return keyPress; }

int P5_keyCode() { return keyCode; }
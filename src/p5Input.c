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

int mouseButton;
int pmouseX, mouseX, pmouseY, mouseY;
int keyCode;
int eventType;

char keyPress[2] = "X\0";

bool isEvent[] = {false,false,false,false,false,false,false,false};

int LEFT_BUTTON, RIGHT_BUTTON, MIDDLE_BUTTON, DOWN;

int p5_mouseX() {
	return mouseX;
}

int p5_mouseY() {
	return mouseY;
}

int p5_pmouseX() {
	return pmouseX;
}

int p5_pmouseY() {
	return pmouseY;
}

int p5_mouseButton() {
	return mouseButton;
}

bool p5_isMousePressed() {
	return isEvent[MOUSE_PRESSED];
}

void p5_mouseEvent(int button, int state,int xpos, int ypos) {
  pmouseX = mouseX;
  pmouseY = mouseY;
  mouseX = xpos;
  mouseY = ypos;
  if (button==LEFT_BUTTON) {
    mouseButton = P5_LEFT;
  } else if (button==RIGHT_BUTTON) {
    mouseButton = P5_RIGHT;
  } else {
    mouseButton = P5_MIDDLE;
  }
  if (state==DOWN) {
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

int p5_IsKeyPressed() {
	return isEvent[KEY_PRESSED];
}

int p5_Key() {
  return keyPress;
}

int P5_KeyCode() {
 return keyCode;
}
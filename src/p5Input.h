/*
 --
 -- p5Input.h
 --
 -- Döiköl Interactive Graphics Environment
 --
 -- Copyright (c) 2017-2021 Armando Arce - armando.arce@gmail.com
 --
 -- This library is free software; you can redistribute it and/or modify
 -- it under the terms of the MIT license. See LICENSE for details.
 --
 */

#include <stdbool.h>

#define P5_BACKSPACE 100
#define P5_TAB 101
#define P5_ENTER 102
#define P5_RETURN 103
#define P5_ESC 104
#define P5_DELETE 105

#define P5_PRESS 9
#define P5_RELEASE 10

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

void p5_mouseMovedFunc(void (*func)(int x, int y));

void p5_mouseDraggedFunc(void (*func)(int x, int y));

void p5_mousePressedFunc(void (*func)(int key, int keyCode));

void p5_mouseReleasedFunc(void (*func)(int x, int y));
	
void p5_mouseClickedFunc(void (*func)());

void p5_keyPressedFunc(void (*func)(int key, int keyCode));

void p5_keyReleasedFunc(void (*func)(int key, int keyCode));

void p5_windowResizedFunc(void (*func)(int w, int h));

int p5_mouseX();

int p5_mouseY();

int p5_pmouseX();

int p5_pmouseY();

int p5_mouseButton();

bool p5_isMousePressed();

void p5_mouseEvent(int button, int state);

void p5_motionEvent(int xpos, int ypos);

void p5_keyPressedEvent(char key, int code);

void p5_keyReleasedEvent(char key, int code);

int p5_isKeyPressed();

char p5_key();

int p5_keyCode();
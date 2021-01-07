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

int p5_mouseX();

int p5_mouseY();

int p5_pmouseX();

int p5_pmouseY();

int p5_mouseButton();

bool p5_isMousePressed();

void p5_mouseEvent(int button, int state,int xpos, int ypos);

void p5_motionEvent(int xpos, int ypos);

void p5_passiveMotionEvent(int xpos, int ypos);

void p5_keyPressedEvent(char key, int code);

void p5_keyReleasedEvent(char key, int code);

int p5_IsKeyPressed();

int p5_Key();

int p5_KeyCode();
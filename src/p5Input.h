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

static int P5_MouseButton(lua_State *L) {
  lua_pushnumber(L,mouseButton);
  return 1;
}

static int P5_IsMousePressed(lua_State *L) {
  lua_pushboolean(L,isEvent[MOUSE_PRESSED]);
  return 1;
}

static void mouseFunc(int button, int state,int xpos, int ypos) {
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
  if (state=DOWN) {
    eventType = MOUSE_PRESSED;
    isEvent[MOUSE_PRESSED] = true;
  } else {
    eventType = MOUSE_RELEASED;
    isEvent[MOUSE_RELEASED] = true;
  }
}

static void motionFunc(int xpos, int ypos) {
  pmouseX = mouseX;
  pmouseY = mouseY;
  mouseX = xpos;
  mouseY = ypos;
  eventType = MOUSE_DRAGGED;
  isEvent[MOUSE_DRAGGED] = true;
}

static void passiveMotionFunc(int xpos, int ypos) {
  pmouseX = mouseX;
  pmouseY = mouseY;
  mouseX = xpos;
  mouseY = ypos;
  eventType = MOUSE_MOVED;
  isEvent[MOUSE_DRAGGED] = true;
}

static void Dkl_ProcessEvent(int eventType) {
  lua_getglobal(L,eventArray[eventType]);
  if (eventType == WINDOW_RESIZED) {
    lua_pushnumber(L, width);
    lua_pushnumber(L, height);
  } else if (eventType == KEY_PRESSED || eventType == KEY_RELEASED) {
    lua_pushstring(L, keyPress);
    lua_pushnumber(L, keyCode);
  } else {
    lua_pushnumber(L, mouseX);
    lua_pushnumber(L, mouseY);
  }
  if (lua_pcall(L, 2, 0, 0)!=0)
    eventFunc[eventType] = false;
  if (eventType == MOUSE_RELEASED && eventFunc[MOUSE_CLICKED]) {
    lua_getglobal(L,eventArray[MOUSE_CLICKED]);
    lua_pushnumber(L, mouseX);
    lua_pushnumber(L, mouseY);
    if (lua_pcall(L, 2, 0, 0)!=0)
      eventFunc[MOUSE_CLICKED] = false;
  }
}

// Keyboard:
// key
// keyCode
// keyPressed()
// keyPressed
// keyReleased()
// keyTyped()

static int Dkl_KeyPressed(char key, int code) {
  keyPress[0] = key;
  keyCode = code;
  eventType = KEY_PRESSED;
  isEvent[KEY_PRESSED] = true;
  return 0;
}

static int Dkl_KeyReleased(char key, int code) {
  keyCode = code;
  eventType = KEY_RELEASED;
  isEvent[KEY_RELEASED] = true;
  return 0;
}

static int P5_IsKeyPressed(lua_State *L) {
  lua_pushboolean(L,isEvent[KEY_PRESSED]);
  return 1;
}

static int P5_Key(lua_State *L) {
  lua_pushstring(L,keyPress);
  return 1;
}

static int P5_KeyCode(lua_State *L) {
  lua_pushnumber(L,keyCode);
  return 1;
}
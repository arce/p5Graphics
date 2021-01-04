#include "p5Environment.h"

static int p5_frameCount() {
	return _frameCount;
}

static int p5_frameRate(int rate) {
	if (rate != 0)
		_frameRate = rate;
  return _frameRate;
}

static void p5_fullScreen() {
}

static int p5_height() {
	return _height;
}

static void p5_noSmooth() {
}

static void p5_size(int width, int height) {
	_width = width;
	_height = height;
}

static void p5_smooth() {
}

static int p5_width() {
	return _width;
}
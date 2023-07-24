#include "p5Transform.h"
#include <VG/openvg.h>
#include <stdlib.h>
#include <string.h>

#define M_PI   3.14159265358979323846264338327950288

VGfloat *mtrx_stack = NULL;
int mtr_ndx = 0;

void p5_popMatrix() {
  mtr_ndx -= 9;
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgLoadMatrix(mtrx_stack+sizeof(VGfloat)*mtr_ndx);
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
  vgLoadMatrix(mtrx_stack+sizeof(VGfloat)*mtr_ndx);
}

void p5_pushMatrix() {
	if (mtrx_stack == NULL)
		mtrx_stack = malloc(sizeof(VGfloat)*900);
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgGetMatrix(mtrx_stack+sizeof(VGfloat)*mtr_ndx);
	mtr_ndx += 9;
}

void p5_resetMatrix() {
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgLoadIdentity();
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
  vgLoadIdentity();
}

void p5_rotate(float radians) {
	float angle = radians * 57.2957795130823208768;
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgRotate(angle);
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
  vgRotate(angle);
}

void p5_scale(int sx, int sy) {
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgScale(sx, sy);
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
  vgScale(sx, sy);
}

void p5_shearX(float angle) {
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgShear(angle, 0.0f);
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
  vgShear(angle, 0.0f);
}

void p5_shearY(float angle) {
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgShear(0.0f, angle);
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
  vgShear(0.0f, angle);
}

void p5_translate(float dx, float dy) {
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgTranslate(dx, dy);
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
  vgTranslate(dx, dy);
}
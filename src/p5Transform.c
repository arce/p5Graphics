#include <string.h>
#include <stdlib.h>
#include <VG/openvg.h>
#include "p5Transform.h"

 void p5_popMatrix() {
  Matrix* temp = mtrx_stack;
  mtrx_stack = mtrx_stack->next;
  
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgLoadMatrix(temp->data);
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
  vgLoadMatrix(temp->data);
}

 void p5_printMatrix() {
  Matrix* temp = mtrx_stack;
  int i,j;
  for (i=0;i<3;i++) {
    for (j=0; j<3; j++)
      printf("%f ",temp->data[i*3+j]);
    printf("\n");
  }
}

 void p5_pushMatrix() {
  Matrix* temp;
  temp = mtrx_new();
  
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgGetMatrix(temp->data);
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
  vgGetMatrix(temp->data);
  temp->next = mtrx_stack;
  mtrx_stack = temp;
}

 void p5_resetMatrix() {
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgLoadIdentity();
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
  vgLoadIdentity();
}

 void p5_rotate(float angle) {
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgRotate(angle);
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
  vgRotate(angle);
}

 void p5_scale(int sx, int sy) {
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgScale(sx,sy);
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
  vgScale(sx,sy);
}

 void p5_shearX(float angle) {
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgShear(angle,0.0f);
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
  vgShear(angle,0.0f);
}

 void p5_shearY(float angle) {
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgShear(0.0f,angle);
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
  vgShear(0.0f,angle);
}

 void p5_translate(float dx, float dy) {
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgTranslate(dx,dy);
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
  vgTranslate(dx,dy);
}
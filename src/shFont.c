#include "shFont.h"

VGfloat VG_GLYPH_ORIGIN[2];

VGFont vgCreateFont(VGint glyphCapacityHint) {
  SHFont *f = malloc(sizeof(SHFont));
  memset(f, 0, sizeof(SHFont));
  f->glyphs = malloc(sizeof(SHGlyph) * glyphCapacityHint);
  memset(f->glyphs, 0, sizeof(SHGlyph) * glyphCapacityHint);
  f->count = glyphCapacityHint;
  return (VGFont)f;
}

void vgDestroyFont(VGFont font) { free(font); }

void vgSetGlyphToPath(VGFont font, VGuint glyphIndex, VGPath path,
                      VGboolean isHinted, const VGfloat glyphOrigin[2],
                      const VGfloat escapement[2]) {
  SHFont *f = (SHFont *)font;
  f->glyphs[glyphIndex].is_path = VG_TRUE;
  f->glyphs[glyphIndex].handle = path;
  f->glyphs[glyphIndex].origin[0] = glyphOrigin[0];
  f->glyphs[glyphIndex].origin[1] = glyphOrigin[1];
  f->glyphs[glyphIndex].escapement[0] = escapement[0];
  f->glyphs[glyphIndex].escapement[1] = escapement[1];
}

void vgSetGlyphToImage(VGFont font, VGuint glyphIndex, VGImage image,
                       const VGfloat glyphOrigin[2],
                       const VGfloat escapement[2]) {
  SHFont *f = (SHFont *)font;
  f->glyphs[glyphIndex].is_path = VG_FALSE;
  f->glyphs[glyphIndex].handle = image;
  f->glyphs[glyphIndex].origin[0] = glyphOrigin[0];
  f->glyphs[glyphIndex].origin[1] = glyphOrigin[1];
  f->glyphs[glyphIndex].escapement[0] = escapement[0];
  f->glyphs[glyphIndex].escapement[1] = escapement[1];
}

void vgClearGlyph(VGFont font, VGuint glyphIndex) {
  SHFont *f = (SHFont *)font;
  SHGlyph g = f->glyphs[glyphIndex];
  if (g.is_path)
    vgDestroyPath(g.handle);
  else
    vgDestroyImage(g.handle);
}

VGfloat _matrix[9];

void vgDrawGlyph(VGFont font, VGuint glyphIndex, VGbitfield paintModes,
                 VGboolean allowAutoHinting) {
  SHFont *f = (SHFont *)font;
  if (paintModes != 0) {
    VGboolean is_path = f->glyphs[glyphIndex].is_path;
    if (is_path)
      vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
    else
      vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
    vgGetMatrix(_matrix);
    vgTranslate(VG_GLYPH_ORIGIN[0] + f->glyphs[glyphIndex].origin[0],
                VG_GLYPH_ORIGIN[1] + f->glyphs[glyphIndex].origin[1]);
    if (is_path)
      vgDrawPath((VGPath)f->glyphs[glyphIndex].handle, paintModes);
    else
      vgDrawImage((VGImage)f->glyphs[glyphIndex].handle);
    vgLoadMatrix(_matrix);
  }
  VG_GLYPH_ORIGIN[0] += f->glyphs[glyphIndex].escapement[0];
  VG_GLYPH_ORIGIN[1] += f->glyphs[glyphIndex].escapement[1];
}

void vgDrawGlyphs(VGFont font, VGint glyphCount, const VGuint *glyphIndices,
                  const VGfloat *adjustments_x, const VGfloat *adjustments_y,
                  VGbitfield paintModes, VGboolean allowAutoHinting) {
  SHFont *f = (SHFont *)font;
  int i;
  float adjx = 0, adjy = 0;
  VGfloat matrix[9];
  vgGetMatrix(matrix);
  for (i = 0; i < glyphCount; i++) {
    if (adjustments_x != NULL)
      adjx = adjustments_x[i];
    if (adjustments_y != NULL)
      adjy = adjustments_y[i];
    int c = (unsigned char)glyphIndices[i];
    if (paintModes != 0) {
      VGboolean is_path = f->glyphs[c].is_path;
      if (is_path)
        vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
      else
        vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
      vgTranslate(VG_GLYPH_ORIGIN[0] + f->glyphs[c].origin[0] + adjx,
                  VG_GLYPH_ORIGIN[1] + f->glyphs[c].origin[1] + adjy);
      if (is_path)
        vgDrawPath((VGPath)f->glyphs[c].handle, paintModes);
      else
        vgDrawImage((VGImage)f->glyphs[c].handle);
      vgLoadMatrix(matrix);
    }
    VG_GLYPH_ORIGIN[0] += f->glyphs[c].escapement[0] + adjx;
    VG_GLYPH_ORIGIN[1] += f->glyphs[c].escapement[1] + adjy;
  }
  vgLoadMatrix(matrix);
}

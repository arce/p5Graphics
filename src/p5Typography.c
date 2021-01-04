#include "p5Typography.h"
#include <stdbool.h>
#include <STB/stb_truetype.h>

VGFont _createFontFromFile(const char *filename, unsigned short size) {

  stbtt_fontinfo font;
  stbtt_vertex *vertices;
  float xpos = 2;
  int i, advance, lsb, w, h, xoff = 0, yoff = 0;
  int x0, y0, x1, y1;
  int glyphIndex;
  int num_verts;

  char filepath[256];
  strcpy(filepath, mainPath);
  fread(ttf_buffer, 1, 1 << 24, fopen(strcat(filepath, filename), "rb"));

  VGPath path;
  VGubyte seg;
  stbtt_InitFont(&font, ttf_buffer, stbtt_GetFontOffsetForIndex(ttf_buffer, 0));
  stbtt_GetFontBoundingBox(&font, &x0, &y0, &x1, &y1);

  float scale = 10.0 / (y1 - y0);

  VGFont fnt = vgCreateFont(font.numGlyphs);
  for (glyphIndex = 0; glyphIndex < font.numGlyphs; glyphIndex++) {
    stbtt_GetCodepointHMetrics(&font, (unsigned char)glyphIndex, &advance,
                               &lsb);
    num_verts =
        stbtt_GetCodepointShape(&font, (unsigned char)glyphIndex, &vertices);
    path = vgCreatePath(VG_PATH_FORMAT_STANDARD, VG_PATH_DATATYPE_F, 1.0f, 0.0f,
                        num_verts, 4,
                        VG_PATH_CAPABILITY_APPEND_TO |
                            VG_PATH_CAPABILITY_PATH_TRANSFORMED_BOUNDS);
    for (i = 0; i < num_verts; ++i) {
      switch (vertices[i].type) {
      case STBTT_vmove:
        seg = VG_MOVE_TO;
        vgAppendPathData(
            path, 1, &seg,
            (VGfloat[]){vertices[i].x * scale, vertices[i].y * scale});
        break;
      case STBTT_vline:
        seg = VG_LINE_TO;
        vgAppendPathData(
            path, 1, &seg,
            (VGfloat[]){vertices[i].x * scale, vertices[i].y * scale});
        break;
      case STBTT_vcurve:
        seg = VG_QUAD_TO;
        vgAppendPathData(
            path, 1, &seg,
            (VGfloat[]){vertices[i].cx * scale, vertices[i].cy * scale,
                        vertices[i].x * scale, vertices[i].y * scale});
        break;
      case STBTT_vcubic:
        seg = VG_CUBIC_TO;
        vgAppendPathData(
            path, 1, &seg,
            (VGfloat[]){vertices[i].cx * scale, vertices[i].cy * scale,
                        vertices[i].cx1 * scale, vertices[i].cy1 * scale,
                        vertices[i].x * scale, vertices[i].y * scale});
        break;
      }
    }
    seg = VG_CLOSE_PATH;
    vgAppendPathData(path, 1, &seg, (VGfloat[]){0.0});
    vgSetGlyphToPath(fnt, glyphIndex, path, VG_FALSE,
                     (VGfloat[]){xoff * scale, yoff * scale},
                     (VGfloat[]){advance * scale, 0});
  }
  return fnt;
}

static int p5_createFont(char *filename, int textHeight) {
  fontCount++;
  fonts[fontCount] = _createFontFromFile(filename, textHeight);
  fHeight[fontCount] = fSize[fontCount] = textHeight;
  return fontCount;
}

VGFont _loadFontFromFile(const char *filename, unsigned short size) {

  stbtt_fontinfo font;
  VGubyte *bitmap;
  float scale, xpos = 2;
  int i, advance, lsb, w, h, xoff, yoff;
  int x0, y0, x1, y1;
  int glyphIndex;

  char filepath[256];
  strcpy(filepath, mainPath);
  fread(ttf_buffer, 1, 1 << 24, fopen(strcat(filepath, filename), "rb"));

  VGImage image;
  VGImageFormat bitmapFormat = VG_sL_8;
  unsigned int lilEndianTest = 1;
  VGImageFormat rgbaFormat;

  if (((unsigned char *)&lilEndianTest)[0] == 1)
    rgbaFormat = VG_sABGR_8888;
  else
    rgbaFormat = VG_sRGBA_8888;

  stbtt_InitFont(&font, ttf_buffer, stbtt_GetFontOffsetForIndex(ttf_buffer, 0));
  VGFont fnt = vgCreateFont(font.numGlyphs);
  scale = stbtt_ScaleForPixelHeight(&font, size);
  for (glyphIndex = 0; glyphIndex < font.numGlyphs; glyphIndex++) {
    stbtt_GetCodepointHMetrics(&font, (unsigned char)glyphIndex, &advance,
                               &lsb);
    bitmap = stbtt_GetCodepointBitmap(
        &font, scale, scale, (unsigned char)glyphIndex, &w, &h, &xoff, &yoff);
    for (i = 0; i < w * h; i++)
      bitmap[i] = 0xFF - bitmap[i];
    image = vgCreateImage(rgbaFormat, w, h, VG_IMAGE_QUALITY_NONANTIALIASED);
    vgImageSubData(image, bitmap, w, bitmapFormat, 0, 0, w, h);
    vgSetGlyphToImage(fnt, glyphIndex, image, (VGfloat[]){xoff, yoff},
                      (VGfloat[]){(int)(advance * scale), 0});
  }
  return fnt;
}

static int p5_loadFont(char *filename, int textHeight) {
  fontCount++;
  fonts[fontCount] = _loadFontFromFile(filename, textHeight);
  fHeight[fontCount] = fSize[fontCount] = textHeight;
  return fontCount;
}

static void p5_text(char *str, int x, int y) {
  VG_GLYPH_ORIGIN[0] = 0;
  VG_GLYPH_ORIGIN[1] = 0;
  int i;
  for (i = 0; i < strlen(str); i++)
    vgDrawGlyph(fonts[fontId], str[i], 0, false);

  int tWidth = VG_GLYPH_ORIGIN[0];
  switch (alignX) {
  case P5_LEFT:
    break;
  case P5_RIGHT:
    x = x - tWidth;
    break;
  case P5_CENTER:
    x = x - tWidth * 0.5f;
    break;
  }
  VG_GLYPH_ORIGIN[0] = 0;
  VG_GLYPH_ORIGIN[1] = 0;
  VGfloat matrix[] = {fSize[fontId] * 0.1f,
                      0.0f,
                      0.0f,
                      0.0f,
                      -fSize[fontId] * 0.1f,
                      0.0f,
                      x,
                      y,
                      1.0f};
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgGetMatrix(backup);
  vgMultMatrix(matrix);

  for (i = 0; i < strlen(str); i++)
    vgDrawGlyph(fonts[fontId], str[i], VG_FILL_PATH, false);

  vgLoadMatrix(backup);
}

static void p5_textFont(int id) { fontId = id; }

static void p5_textAlign(int xalign, int yalign) {
  alignX = xalign;
  alignY = yalign;
}

static void p5_textLeading(int textLead) { textLeading = textLead; }

static void p5_textSize(int id) { fHeight[fontId] = fSize[fontId] = id; }

static int p5_textWidth(char *str) {
  VG_GLYPH_ORIGIN[0] = 0;
  VG_GLYPH_ORIGIN[1] = 0;
  int i;
  for (i = 0; i < strlen(str); i++)
    vgDrawGlyph(fonts[fontId], str[i], 0, false);
  return VG_GLYPH_ORIGIN[0];
}
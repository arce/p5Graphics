#include <stdlib.h>
#include <string.h>
#include <VG/openvg.h>

#ifndef __SHFONT_H
#define __SHFONT_H

typedef VGHandle VGFont;

typedef enum {
  VG_FONT_NUM_GLYPHS                          = 0x2F00
} VGFontParamType;

/* Text */

VGFont vgCreateFont(VGint glyphCapacityHint);
void vgDestroyFont(VGFont font);
void vgSetGlyphToPath(VGFont font,
                                              VGuint glyphIndex,
                                              VGPath path,
                                              VGboolean isHinted,
                                              const VGfloat glyphOrigin [2],
                                              const VGfloat escapement[2]);
void vgSetGlyphToImage(VGFont font,
                                               VGuint glyphIndex,
                                               VGImage image,
                                               const VGfloat glyphOrigin [2],
                                               const VGfloat escapement[2]);
void vgClearGlyph(VGFont font,VGuint glyphIndex);
void vgDrawGlyph(VGFont font, 
                                         VGuint glyphIndex,
                                         VGbitfield paintModes,
                                         VGboolean allowAutoHinting);
void vgDrawGlyphs(VGFont font,
                                          VGint glyphCount,
                                          const VGuint *glyphIndices,
                                          const VGfloat *adjustments_x,
                                          const VGfloat *adjustments_y,
                                          VGbitfield paintModes,
                                          VGboolean allowAutoHinting); 

typedef struct {
   VGboolean is_path;
   VGHandle handle;
   VGfloat origin[2];
   VGfloat escapement[2];
} SHGlyph;

typedef struct {
		int count;
		int font_height;
		float font_scale;
		SHGlyph* glyphs;
} SHFont;

#define _ITEM_T SHFont*

static VGfloat VG_GLYPH_ORIGIN[2] = {0,0};

#endif /* __SHFONT_H */
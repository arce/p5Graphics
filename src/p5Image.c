#include <stdlib.h>
#include <string.h>

#include "p5Image.h"
#include "p5Transform.h"
#include <STB/stb_image.h>
#include <VG/openvg.h>

// Image commands:
// createImage()

static int p5_createImage(int width, int height) {
  imageCount++;
  unsigned int lilEndianTest = 1;
  VGImageFormat rgbaFormat;
  if (((unsigned char *)&lilEndianTest)[0] == 1)
    rgbaFormat = VG_sABGR_8888;
  else
    rgbaFormat = VG_sRGBA_8888;
  iWidth[imageCount] = width;
  iHeight[imageCount] = height;
  images[imageCount] =
      vgCreateImage(rgbaFormat, width, height, VG_IMAGE_QUALITY_BETTER);
  return imageCount;
}

// Image Loading & Displaying commands:
// imageWidth() -- Diököl extension
// imageHeight() -- Diököl extension
// image()
// imageMode()
// loadImage()
// noTint()
// requestImage()
// tint()

static int p5_imageWidth(int imageId) { return (iWidth[imageId]); }

static int p5_imageHeight(int imageId) { return iHeight[imageId]; }

static void p5_image(int imageId, int x, int y, int w, int h) {
  VGPaint fill;
  if (w == 0)
    w = iWidth[imageId];
  if (h == 0)
    h = iHeight[imageId];
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
  vgGetMatrix(backup);
  switch (_imageMode) {
  case P5_CENTER:
    x = x - w / 2;
    y = y - h / 2;
    break;
  case P5_CORNERS:
    w = abs(w - x);
    h = abs(h - y);
    break;
  }
  const VGfloat coords[9] = {w / iWidth[imageId],
                             0.0f,
                             0.0f,
                             0.0f,
                             h / iHeight[imageId],
                             0.0f,
                             x,
                             y,
                             1.0f};
  vgMultMatrix(coords);
  vgDrawImage(images[imageId]);
  vgLoadMatrix(backup);
}

static void p5_imageMode(int imageMode) { _imageMode = imageMode; }

VGImage _createImageFromMemory(unsigned char const *buffer, int len, int *w,
                               int *h) {
  VGImage img;
  VGint width;
  VGint height;
  VGint dstride;
  VGint n;
  VGubyte *data;
  int i, j;

  unsigned int lilEndianTest = 1;
  VGImageFormat rgbaFormat;
  if (((unsigned char *)&lilEndianTest)[0] == 1)
    rgbaFormat = VG_sABGR_8888;
  else
    rgbaFormat = VG_sRGBA_8888;

  data =
      stbi_load_from_memory(buffer, len, &width, &height, &n, STBI_rgb_alpha);
  dstride = width * 4;

  if (data == NULL) {
    printf("Failed creating image!\n");
    return VG_INVALID_HANDLE;
  }

  *w = width;
  *h = height;
  img = vgCreateImage(rgbaFormat, width, height, VG_IMAGE_QUALITY_BETTER);
  vgImageSubData(img, data, dstride, rgbaFormat, 0, 0, width, height);
  stbi_image_free(data);
  return img;
}

VGImage _createImageFromFile(const char *filename, int *w, int *h) {
  VGImage img;
  VGint width;
  VGint height;
  VGint dstride;
  VGint n;
  VGubyte *data;
  int i, j;

  unsigned int lilEndianTest = 1;
  VGImageFormat rgbaFormat;
  if (((unsigned char *)&lilEndianTest)[0] == 1)
    rgbaFormat = VG_sABGR_8888;
  else
    rgbaFormat = VG_sRGBA_8888;

  data = stbi_load(filename, &width, &height, &n, STBI_rgb_alpha);
  dstride = width * 4;

  if (data == NULL) {
    printf("Failed opening '%s' for reading!\n", filename);
    return VG_INVALID_HANDLE;
  }

  *w = width;
  *h = height;
  img = vgCreateImage(rgbaFormat, width, height, VG_IMAGE_QUALITY_BETTER);
  vgImageSubData(img, data, dstride, rgbaFormat, 0, 0, width, height);
  stbi_image_free(data);
  return img;
}

static int P5_ImportImage(uint8_t *buffer, int len) {
  imageCount++;
  images[imageCount] = _createImageFromMemory(buffer, len, &iWidth[imageCount],
                                              &iHeight[imageCount]);
  return imageCount;
}

static int p5_loadImage(char *filename) {
  imageCount++;
  images[imageCount] =
      _createImageFromFile(filename, &iWidth[imageCount], &iHeight[imageCount]);
  return imageCount;
}

// Image Pixels commands:
// blend()
// copy()
// filter()
// get()
// loadPixels()
// pixels[]
// set()
// updatePixels()

static void p5_loadPixels(int imageId) {
  VGImage image = images[imageId];
  int width = iWidth[imageId], height = iHeight[imageId];
  uint32_t n = width * height;
  uint8_t** parray = malloc(sizeof(uint8_t) * n * 4 + 4);

  unsigned int lilEndianTest = 1;
  VGImageFormat rgbaFormat;
  if (((unsigned char *)&lilEndianTest)[0] == 1)
    rgbaFormat = VG_sABGR_8888;
  else
    rgbaFormat = VG_sRGBA_8888;
  vgGetImageSubData(image, *parray + 4, width * 4, rgbaFormat, 0, 0, width,
                    height);
  (*parray)[0] = ((n >> 24) & 0xFF);
  (*parray)[1] = ((n >> 16) & 0xFF);
  (*parray)[2] = ((n >> 8) & 0xFF);
  (*parray)[3] = ((n)&0xFF);
}

static void p5_updatePixels(int imageId, uint8_t **parray) {
  VGImage image = images[imageId];
  int width = iWidth[imageId], height = iHeight[imageId];

  unsigned int lilEndianTest = 1;
  VGImageFormat rgbaFormat;
  if (((unsigned char *)&lilEndianTest)[0] == 1)
    rgbaFormat = VG_sABGR_8888;
  else
    rgbaFormat = VG_sRGBA_8888;
  vgImageSubData(image, *parray + 4, width * 4, rgbaFormat, 0, 0, width,
                 height);
}

// Rendering commands:
// clip()
// noClip()

static void p5_clip(int x, int y, int w, int h) {
  vgSetiv(VG_SCISSORING, VG_TRUE, 0);
  VGint coords[4] = {x, y, w, h};
  vgSetiv(VG_SCISSOR_RECTS, 4, coords);
}

static void p5_noClip() { vgSetiv(VG_SCISSORING, VG_FALSE, 0); }
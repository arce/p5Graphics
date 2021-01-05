#include "p5Shapes.h"
#include "p5Math.h"

void createPaths() {

  VGbitfield capabilites =
      VG_PATH_CAPABILITY_APPEND_TO | VG_PATH_CAPABILITY_MODIFY;

  arc_path = vgCreatePath(VG_PATH_FORMAT_STANDARD, VG_PATH_DATATYPE_F, 1.0f,
                          0.0f, 4, 4, capabilites);
  vguArc(arc_path, 0, 0, 1, 1, 0, 2 * M_PI, VGU_ARC_PIE);

  ellipse_path = vgCreatePath(VG_PATH_FORMAT_STANDARD, VG_PATH_DATATYPE_F, 1.0f,
                              0.0f, 4, 12, capabilites);
  vguEllipse(ellipse_path, 0.0f, 0.0f, 1.0f, 1.0f);

  line_path = vgCreatePath(VG_PATH_FORMAT_STANDARD, VG_PATH_DATATYPE_F, 1.0f,
                           0.0f, 2, 4, capabilites);
  vguLine(line_path, 0.0f, 0.0f, 1.0f, 1.0f);

  point_path = vgCreatePath(VG_PATH_FORMAT_STANDARD, VG_PATH_DATATYPE_F, 1.0f,
                            0.0f, 5, 5, capabilites);
  vguRect(point_path, 0.0f, 0.0f, 1.0f, 1.0f);

  VGfloat points[] = {0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f};

  quad_path = vgCreatePath(VG_PATH_FORMAT_STANDARD, VG_PATH_DATATYPE_F, 1.0f,
                           0.0f, 2, 5, capabilites);
  vguPolygon(quad_path, points, 4, VG_TRUE);

  rect_path = vgCreatePath(VG_PATH_FORMAT_STANDARD, VG_PATH_DATATYPE_F, 1.0f,
                           0.0f, 2, 5, capabilites);
  vguRect(rect_path, 0.0f, 0.0f, 1.0f, 1.0f);

  triangle_path = vgCreatePath(VG_PATH_FORMAT_STANDARD, VG_PATH_DATATYPE_F,
                               1.0f, 0.0f, 2, 6, capabilites);
  vguPolygon(triangle_path, points, 3, VG_TRUE);

  VGubyte segments[] = {VG_MOVE_TO_ABS, VG_CUBIC_TO};
  VGfloat coords[] = {0.0f, 0.0f, 1.0f, -1.0f, 2.0f, 1.0f, 3.0f, 0.0f};

  bezier_path = vgCreatePath(VG_PATH_FORMAT_STANDARD, VG_PATH_DATATYPE_F, 1.0f,
                             0.0f, 2, 8, capabilites);
  vgAppendPathData(bezier_path, 2, segments, coords);

  curve_path = vgCreatePath(VG_PATH_FORMAT_STANDARD, VG_PATH_DATATYPE_F, 1.0f,
                            0.0f, 2, 6, capabilites);
  segments[1] = VG_QUAD_TO;
  vgAppendPathData(curve_path, 2, segments, coords);

  shape_path = vgCreatePath(VG_PATH_FORMAT_STANDARD, VG_PATH_DATATYPE_F, 1.0f,
                            0.0f, 2, 6, capabilites);
}

void p5_arc(float x, float y, float a, float _start, float _stop, int type) {
  VGUArcType arcType = VGU_ARC_PIE;
  VGfloat b, start, stop;
  b = a;
  start = _deg(_start);
  stop = _deg(_stop);

  if (type == P5_PIE)
    arcType = VGU_ARC_PIE;
  else if (type == P5_CHORD)
    arcType = VGU_ARC_CHORD;
  else if (type == P5_OPEN)
    arcType = VGU_ARC_OPEN;

  vgClearPath(arc_path, VG_PATH_CAPABILITY_APPEND_TO);
  switch (ellipseMode) {
  case P5_CORNERS:
    vguArc(arc_path, (x + a) * 0.5f, (y + b) * 0.5f, a - x, b - y, start,
           stop - start, arcType);
    break;
  case P5_CENTER:
    vguArc(arc_path, x, y, a, b, start, stop - start, arcType);
    break;
  case P5_RADIUS:
    vguArc(arc_path, x, y, a * 2.0f, b * 2.0f, start, stop - start, arcType);
    break;
  case P5_CORNER:
    vguArc(arc_path, (x + a) * 0.5f, (y + b) * 0.5f, a, b, start, stop - start,
           arcType);
    break;
  }

  vgDrawPath(arc_path, fillEnable | strokeEnable);
}

void _ellipse(VGfloat cx, VGfloat cy, VGfloat w, VGfloat h) {
  VGfloat coords[12] = {cx + w / 2, cy,       w * 0.5f, h * 0.5f, 0.0f, -w,
                        0.0f,       w * 0.5f, h * 0.5f, 0.0f,     w,    0.0f};

  switch (ellipseMode) {
  case P5_CENTER:
    break;
  case P5_CORNERS:
    coords[2] = coords[2] - coords[0];
    coords[3] = coords[3] - coords[1];
    coords[5] = -coords[2];
    break;
  case P5_CORNER:
    coords[0] = coords[0] - coords[2] * 0.5f;
    coords[1] = coords[1] - coords[3] * 0.5f;
    break;
  case P5_RADIUS:
    coords[0] = coords[0] - coords[2];
    coords[1] = coords[1] - coords[3];
    coords[2] = coords[2] * 2;
    coords[3] = coords[3] * 2;
    coords[5] = -coords[2];
    break;
  };

  vgModifyPathCoords(ellipse_path, 0, 3, coords);
  vgDrawPath(ellipse_path, fillEnable | strokeEnable);
}

void p5_circle(float x, float y, float a) { _ellipse(x, y, a, a); }

void p5_ellipse(float x, float y, float a, float b) { _ellipse(x, y, a, b); }

void p5_line(float x, float y, float a, float b) {
  const VGfloat coords[4] = {x, y, a, b};

  vgModifyPathCoords(line_path, 0, 2, coords);
  if (strokeEnable)
    vgDrawPath(line_path, VG_STROKE_PATH);
}

void p5_point(float x, float y) {
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgGetMatrix(s_backup);
  vgTranslate(x, y);
  if (fillEnable)
    vgDrawPath(point_path, VG_FILL_PATH);
  vgLoadMatrix(s_backup);
}

void p5_quad(float x, float y, float a, float b, float c, float d, float e,
             float f) {
  const VGfloat coords[8] = {x, y, a, b, c, d, e, f};

  vgModifyPathCoords(quad_path, 0, 4, coords);
  vgDrawPath(quad_path, fillEnable | strokeEnable);
}

void _rect(float a, float b, float c, float d) {
  VGfloat coords[5] = {a, b, c, d, -c};

  switch (rectMode) {
  case P5_CORNER:
    break;
  case P5_CORNERS:
    coords[2] = coords[2] - coords[0];
    coords[3] = coords[3] - coords[1];
    coords[4] = -coords[2];
    break;
  case P5_CENTER:
    coords[0] = coords[0] - coords[2] * 0.5f;
    coords[1] = coords[1] - coords[3] * 0.5f;
    break;
  case P5_RADIUS:
    coords[0] = coords[0] - coords[2];
    coords[1] = coords[1] - coords[3];
    coords[2] = coords[2] * 2;
    coords[3] = coords[3] * 2;
    coords[4] = -coords[2];
    break;
  };

  vgModifyPathCoords(rect_path, 0, 4, coords);
  vgDrawPath(rect_path, fillEnable | strokeEnable);
}

void p5_rect(float a, float b, float c, float d) { _rect(a, b, c, d); }

void p5_square(float a, float b, float c) { _rect(a, b, c, c); }

void p5_triangle(float x, float y, float a, float b, float c, float d) {
  const VGfloat coords[6] = {x, y, a, b, c, d};

  vgModifyPathCoords(quad_path, 0, 3, coords);
  vgDrawPath(quad_path, fillEnable | strokeEnable);
}

void p5_bezier(float x, float y, float a, float b, float c, float d, float e,
               float f) {
  const VGfloat coords[8] = {x, y, a, b, c, d, e, f};

  vgModifyPathCoords(bezier_path, 0, 2, coords);
  vgDrawPath(bezier_path, fillEnable | strokeEnable);
}

void p5_curve(float x, float y, float a, float b, float c, float d) {
  const VGfloat coords[6] = {x, y, a, b, c, d};

  vgModifyPathCoords(curve_path, 0, 2, coords);
  vgDrawPath(curve_path, fillEnable | strokeEnable);
}

void p5_ellipseMode(int mode) { ellipseMode = mode; }

void p5_rectMode(int mode) { rectMode = mode; }

void p5_strokeCap(int cap) { vgSeti(VG_STROKE_CAP_STYLE, cap); }

void p5_strokeJoin(int join) { vgSeti(VG_STROKE_JOIN_STYLE, join); }

void p5_strokeWeight(float weight) { vgSetf(VG_STROKE_LINE_WIDTH, weight); }

void p5_strokeMiter(float miter) { vgSetf(VG_STROKE_MITER_LIMIT, miter); }

void p5_beginShape(int kindShape) {
  shape_path = vgCreatePath(VG_PATH_FORMAT_STANDARD, VG_PATH_DATATYPE_F, 1.0f,
                            0.0f, 4, 4, VG_PATH_CAPABILITY_APPEND_TO);
  pathSize = 0;
}

void p5_bezierVertex(float x, float y, float a, float b, float c, float d) {
  VGubyte seg = VG_CUBIC_TO;
  const VGfloat coords[6] = {x, y, a, b, c, d};
  vgAppendPathData(shape_path, 1, &seg, coords);
}

void p5_curveVertex() {}

void p5_endShape(int mode) {
  VGubyte seg = -1;
  if (mode == 1) {
    seg = VG_CLOSE_PATH;
    VGfloat data = 0.0f;
    vgAppendPathData(shape_path, 1, &seg, &data);
  }
  vgDrawPath(shape_path, fillEnable | strokeEnable);
}

void p5_quadraticVertex(float x, float y, float w, float h) {
  VGubyte seg = VG_QUAD_TO;
  const VGfloat coords[4] = {x, y, w, h};
  vgAppendPathData(shape_path, 1, &seg, coords);
}

void p5_vertex(int x, int y) {
  VGubyte seg;
  int closePath = 0;
  int points = 0;
  const VGfloat coords[2] = {x, y};
  switch (kindShape) {
  case P5_POINTS:
    seg = VG_MOVE_TO;
    points = 1;
    break;
  case P5_POLYLINE:
    if (pathSize == 0)
      seg = VG_MOVE_TO;
    else
      seg = VG_LINE_TO;
    break;
  case P5_LINES:
    if (pathSize % 2 == 0)
      seg = VG_MOVE_TO;
    else
      seg = VG_LINE_TO;
    break;
  case P5_TRIANGLES:
    if (pathSize % 3 == 0)
      seg = VG_MOVE_TO;
    else {
      seg = VG_LINE_TO;
      if (pathSize % 3 == 2)
        closePath = 1;
    }
    break;
  case P5_QUADS:
    if (pathSize % 4 == 0)
      seg = VG_MOVE_TO;
    else {
      seg = VG_LINE_TO;
      if (pathSize % 4 == 3)
        closePath = 1;
    }
    break;
  }
  pathSize++;
  vgAppendPathData(shape_path, 1, &seg, coords);
  if (points) {
    seg = VG_LINE_TO;
    vgAppendPathData(shape_path, 1, &seg, coords);
  }
  if (closePath) {
    seg = VG_CLOSE_PATH;
    vgAppendPathData(shape_path, 1, &seg, coords);
  }
}

int p5_saveShape(int seg) {
  if (seg == 1) {
    seg = VG_CLOSE_PATH;
    VGfloat data = 0.0f;
    vgAppendPathData(shape_path, 1, &seg, &data);
  }
  pathCount++;
  shape_paths[pathCount] = shape_path;
  return pathCount;
}

void p5_shape(int pid, int w, int h) {
  const VGfloat coords[9] = {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, w, h, 1.0f};
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgGetMatrix(s_backup);
  vgMultMatrix(coords);
  vgDrawPath(shape_paths[pid], fillEnable | strokeEnable);
  vgLoadMatrix(s_backup);
}

void p5_shapeMode(int mode) { shapeMode = mode; }

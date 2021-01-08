#ifndef _P5LIB_H_
#define _P5LIB_H_ 1

#if _WIN32
#include <Windows.h>
#endif
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define P5_CLOSE 0
#define P5_CENTER 1
#define P5_CORNER 2
#define P5_CORNERS 3
#define P5_RADIUS 4
#define P5_TRIANGLES 5

#define P5_LEFT 6
#define P5_RIGHT 7
#define P5_CHORD 8
#define P5_PIE 9
#define P5_OPEN 10

#define P5_MOUSE_PRESSED 11
#define P5_MOUSE_MOVED 12
#define P5_KEY_PRESSED 13

#define P5_PI 3.1415926f
#define P5_TWO_PI 6.283f
#define P5_HALF_PI 1.5707963f
#define P5_QUARTER_PI 0.78539815f

typedef struct PointF {
  float X;
  float Y;
} PointF;

typedef struct Color {
  float red,green,blue,alpha;
} Color;

Color *color_make(float red,float green,float blue,float alpha) {
  Color *c;
  c = malloc(sizeof(Color));
  c->red = red; c->green = green;
  c->blue = blue; c->alpha = alpha;
  return c;
}

typedef struct Style Style;

typedef struct Style {
  Color *fill;
  Color *stroke;
  Style *next;
} Style;

Style *style_make(Style *next,Color *fill, Color *stroke) {
    Style *s;
    s = malloc(sizeof(Style));
    s->fill=fill;
    s->stroke=stroke;
    s->next=next;
    return s;
}

Style *styles = NULL;

// Global variables
char title[] = "GDServer - Graphics Display Server"; // Windowed mode's title
char *_message;
int p5_width = 100;
int p5_height = 100;
int p5_mouseX = 0;
int p5_mouseY = 0;
int p5_pmouseX = 0;
int p5_pmouseY = 0;
char p5_key;
int p5_frameCount = 0;
int _rate = 2147483647;
int _textAlign = P5_LEFT;
float _textRatio = 0.112f;

Color *_fill;
Color *_stroke;

int _fillFlag = 1;
int _strokeFlag = 1;
int _rectMode = P5_CORNER;
int _ellipseMode = P5_CORNER;

int p5_mousePressed = 0;
int p5_keyPressed = 0;
int p5_mouseMoved = 0;
int _printFlag = 0;
int _smoothFlag = 0;

int _mousePressedDef = 0;
int _keyPressedDef = 0;
int _mouseMovedDef = 0;
int _setupDef = 0;
int _drawDef = 0;
float _lineWidth = 1;
int _n_seg = 20;

GLdouble clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;

typedef void (*functiontype)();

functiontype _mousePressed;

functiontype _mouseMoved;

functiontype _keyPressed;

functiontype _setup;

functiontype _draw;

float p5_to_degrees(float radians) { return radians /  P5_PI * 180.0; }

float p5_to_radians(float degrees) { return degrees * P5_PI / 180; }

void p5_mousePressedFunc(functiontype param) {
  _mousePressed = param;
  _mousePressedDef = 1;
}

void p5_mouseMovedFunc(functiontype param) {
  _mouseMoved = param;
  _mouseMovedDef = 1;
}

void p5_keyPressedFunc(functiontype param) {
  _keyPressed = param;
  _keyPressedDef = 1;
}

void p5_setupFunc(functiontype param) {
  _setup = param;
  _setupDef = 1;
}

void p5_drawFunc(functiontype param) {
  _draw = param;
  _drawDef = 1;
}

void _display() {
  glLoadIdentity();
  if (_mousePressedDef && p5_mousePressed)
    _mousePressed();
  if (_keyPressedDef && p5_keyPressed)
    _keyPressed();
  if (_mouseMovedDef && p5_mouseMoved)
    _mouseMoved();
  if (_drawDef)
    _draw();
  if (_printFlag) {
    printf("%s\n", _message);
    _printFlag = 0;
  }
  p5_mousePressed = 0;
  p5_keyPressed = 0;
  p5_mouseMoved = 0;
  p5_frameCount++;
  
  glFlush();
  glutSwapBuffers();
}

void _specialKeys(){};

void _keyboard(unsigned char k, int x, int y) {
  p5_key = k;
  p5_keyPressed = 1;
  glutPostRedisplay();
  switch (p5_key) {
  case 27: // ESC key
    exit(0);
    break;
  }
}

void _mouseMotion(int x, int y) {
  p5_pmouseX = p5_mouseX;
  p5_mouseX = x;
  p5_pmouseY = p5_mouseY;
  p5_mouseY = y;
  p5_mouseMoved = 1;
  glutPostRedisplay();
}

void _mouseButton(int button, int state, int x, int y) {
  p5_pmouseX = p5_mouseX;
  p5_mouseX = x;
  p5_pmouseY = p5_mouseY;
  p5_mouseY = y;
  p5_mousePressed = 1;
  glutPostRedisplay();
}

void _timer() {
  glutPostRedisplay();
  glutTimerFunc(_rate, _timer, 0);
}

void p5_frameRate(int rate) {
  _rate = 1 / rate * 1000;
  glutTimerFunc(_rate, _timer, 0);
}

void p5_ellipse(float cx, float cy, float w, float h) {
  GLdouble vertices[180];
  int parts = 90;
  int t;
  for (t = 0; t < parts; t++) {
    float theta = 2.0f * 3.1415926f * t / parts;
    float x = w / 2 * cosf(theta);
    float y = h / 2 * sinf(theta);
	vertices[t*2] = x + cx;
	vertices[t*2+1] = y + cy;
  }
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(2, GL_DOUBLE, 0, vertices);

  if (_fillFlag) {
	glColor4f(_fill->red,_fill->green,_fill->blue,_fill->alpha);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDrawArrays(GL_TRIANGLE_FAN,0,90);
  }
  if (_strokeFlag) {
    glColor4f(_stroke->red,_stroke->green,_stroke->blue,_stroke->alpha);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_LINE_LOOP,0,90);
  }
  glDisableClientState(GL_VERTEX_ARRAY);
}

void p5_ellipseMode(int mode) { _ellipseMode = mode; }

void p5_arc (float cx, float cy, float w, float h, float start, float end, int mode) {
    GLdouble vertices[180];
    float part = 2.0f * 3.1415926f / 90.0f;
    int t=0;
	if (mode==P5_PIE) {
	  vertices[0] = cx;
      vertices[1] = cy;
	  t++;
    }
    
	for (float theta = start; theta < end ; theta+=part) {
      float x = w / 2 * cosf(theta);
      float y = h / 2 * sinf(theta);
  	  vertices[t*2] = x + cx;
  	  vertices[t*2+1] = y + cy;
	  t++;
    }
	if (mode==P5_CHORD||mode==P5_PIE) {
      vertices[t*2] = vertices[0];
      vertices[t*2+1] = vertices[1];
	  t++;
	}

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_DOUBLE,0,vertices);

    if (_fillFlag) {
  	  glColor4f(_fill->red,_fill->green,_fill->blue,_fill->alpha);
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  	  glDrawArrays(GL_TRIANGLE_FAN,0,t);
    }
    if (_strokeFlag) {
      glColor4f(_stroke->red,_stroke->green,_stroke->blue,_stroke->alpha);
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  	  glDrawArrays(GL_LINE_STRIP,0,t);
    }
    glDisableClientState(GL_VERTEX_ARRAY);
}

void p5_quad (double x0, double y0,
	 	   double x1, double y1,
		   double x2, double y2,
		   double x3, double y3) {
	GLdouble vertices[] = {
					x0, y0,
					x1, y1,
					x2, y2,
					x3, y3
			};
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_DOUBLE, 0, vertices);

	if (_fillFlag) {
      glColor4f(_fill->red,_fill->green,_fill->blue,_fill->alpha);
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      glDrawArrays(GL_QUADS,0,4);
	}
	if (_strokeFlag) {
		glColor4f(_stroke->red,_stroke->green,_stroke->blue,_stroke->alpha);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDrawArrays(GL_QUADS,0,4);
	}

	glDisableClientState(GL_VERTEX_ARRAY);

}

void p5_rect (float x, float y, float a, float b) {
	switch (_rectMode) {
	case P5_CORNER:
		p5_quad (x, y, x+a, y, x+a, y+b, x, y+b);
		break;
	case P5_CENTER:
		p5_quad (x-a/2, y-b/2, x+a/2, y-b/2, x+a/2, y+b/2, x-a/2, y+b/2);
    	break;
    case P5_RADIUS:
		p5_quad (x-a, y-b, x+a, y-b, x+a, y+b, x-a, y+b);
	   	break;
	case P5_CORNERS:
		p5_quad (x, y, a, y, a, b, x, b);
	   	break;
	}
}

void p5_rectMode(int mode) { _rectMode = mode; }

void p5_line(float x0, float y0, float x1, float y1) {
  GLdouble vertices[] = {
			x0, y0,
			x1, y1
  };
  
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(2, GL_DOUBLE, 0, vertices);
  if (_strokeFlag) {
    glColor4f(_stroke->red,_stroke->green,_stroke->blue,_stroke->alpha);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_LINES,0,2);
  }
  glDisableClientState(GL_VERTEX_ARRAY);
}

void p5_triangle (double x0, double y0,
			   double x1, double y1,
			   double x2, double y2) {
	GLdouble vertices[] = {
			x0, y0,
			x1, y1,
			x2, y2
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_DOUBLE, 0, vertices);

	if (_fillFlag) {
		glColor4f(_fill->red,_fill->green,_fill->blue,_fill->alpha);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glDrawArrays(GL_TRIANGLES,0,3);
	}
	if (_strokeFlag) {
		glColor4f(_stroke->red,_stroke->green,_stroke->blue,_stroke->alpha);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDrawArrays(GL_TRIANGLES,0,3);
	}
	glDisableClientState(GL_VERTEX_ARRAY);

}

void p5_point (double x0, double y0) {
    GLdouble vertices[] = {
            x0, y0
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_DOUBLE, 0, vertices);
    if (_strokeFlag) {
      glColor4f(_stroke->red,_stroke->green,_stroke->blue,_stroke->alpha);
      glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
      glDrawArrays(GL_POINTS,0,1);
    }
    glDisableClientState(GL_VERTEX_ARRAY);
}

void p5_bezierDetail(int n_seg) {
    _n_seg = n_seg;
}

void p5_bezier(float x1,float y1,float x2,float y2,
               float x3,float y3,float x4,float y4) {
    unsigned int i;
    double pts[_n_seg+1][2];
    for (i=0; i <= _n_seg; ++i) {
        double t = (double)i / (double)_n_seg;
        double a = pow((1.0 - t),3.0);
        double b = 3.0 * t * pow((1.0 - t),2.0);
        double c = 3.0 * pow(t, 2.0) * (1.0-t);
        double d = pow(t, 3.0);
        double x = a * x1 + b * x2 + c * x3 + d * x4;
        double y = a * y1 + b * y2 + c * y3 + d * y4;
        pts[i][0] = x;
        pts[i][1] = y;
    }

    for (i=0; i < _n_seg; ++i) {
        int j = i + 1;
        p5_line( pts[i][0], pts[i][1],
             pts[j][0], pts[j][1] );
    }
}

void p5_curve(float x0,float y0,float x1,float y1,
              float x2,float y2,float x3,float y3) {
    unsigned int i;
    double pts[_n_seg+1][2];
    
    double aX = (2.0f * x1);
    double aY = (2.0f * y1);
    double bX = (-x0 + x2);
    double bY = (-y0 + y2);
    double cX = (2.0f * x0 - 5.0f * x1 + 4 * x2 - x3);
    double cY = (2.0f * y0 - 5.0f * y1 + 4 * y2 - y3);
    double dX = (-x0 + 3.0f * x1 - 3.0f * x2 + x3);
    double dY = (-y0 + 3.0f * y1 - 3.0f * y2 + y3);
    
    for (i=0; i <= _n_seg; ++i) {
        double t = (double)i / (double)_n_seg;
        float t2 = t * t;
        float t3 = t2 * t;
        double x = 0.5f * (aX + bX * t + cX * t2 + dX * t3);
        double y = 0.5f * (aY + bY * t + cY * t2 + dY * t3);
        pts[i][0] = x;
        pts[i][1] = y;
    }
    
    for (i=0; i < _n_seg; ++i) {
        int j = i + 1;
        p5_line( pts[i][0], pts[i][1],
                pts[j][0], pts[j][1] );
    }
}

void p5_background(unsigned char color) {
  glClearColor(color / 255.f, color / 255.f, color / 255.f, 1);
  glClear(GL_COLOR_BUFFER_BIT);
}

void p5_backgroundRGB(unsigned char r, unsigned char g, unsigned char b) {
  glClearColor(r / 255.f, g / 255.f, b / 255.f, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void p5_noFill() { _fillFlag = 0; }

void p5_noStroke() { _strokeFlag = 0; }

void p5_fillRGBA(unsigned char r, unsigned char g, unsigned char b,
                 unsigned char a) {
  _fillFlag = 1;
  _fill = color_make(r/255.f,g/255.f,b/255.f,a/255.f);
}

void p5_fillRGB(unsigned char r, unsigned char g, unsigned char b) {
  p5_fillRGBA(r, g, b, 255);
}

void p5_fillA(unsigned char c, unsigned char a) { p5_fillRGBA(c, c, c,a); }

void p5_fill(unsigned char c) { p5_fillRGB(c, c, c); }

void p5_strokeRGBA(unsigned char r, unsigned char g, unsigned char b,
                   unsigned char a) {
  _strokeFlag = 1;
  _stroke = color_make(r/255.f,g/255.f,b/255.f,a/255.f);
}

void p5_strokeRGB(unsigned char r, unsigned char g, unsigned char b) {
  p5_strokeRGBA(r, g, b, 255);
}

void p5_strokeA(unsigned char c, unsigned char a) { p5_strokeRGBA(c, c, c, a); }

void p5_stroke(unsigned char c) { p5_strokeRGB(c, c, c); }

void p5_getMatrix (double matrix [16]) {
  glGetDoublev (GL_MODELVIEW_MATRIX, matrix);
}

void p5_applyMatrix (double matrix [16]) {
  glMultMatrixd (matrix);
}

void p5_resetMatrix() {  glLoadIdentity(); }

void p5_pushMatrix() { glPushMatrix(); }

void p5_popMatrix() { glPopMatrix(); }

void p5_translate(float x, float y) { glTranslatef(x, y, 0); }

void p5_rotate(float a) {
  glRotatef(p5_to_degrees(a), 0.0f, 0.0f, 1.0f);
}

void p5_pushStyle() {
  styles = style_make(styles,_fill,_stroke);
}

void p5_popStyle() {
  if (styles==NULL) return;
  _fill = styles->fill;
  _stroke = styles->stroke;
  styles = styles->next;
}

void p5_scaleXY(float x, float y) { glScalef(x, y, 1); }

void p5_scale(float x) { glScalef(x, x, 1); }

void p5_clear() {
  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void p5_smooth() {
  glEnable(GL_LINE_SMOOTH);
  glEnable(GL_POLYGON_SMOOTH);
  glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
  glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
}

void p5_noSmooth() {
  glDisable(GL_LINE_SMOOTH);
  glDisable(GL_POLYGON_SMOOTH);
}

void p5_println(char title[]) {
  _message = title;
  _printFlag = 1;
}

int p5_random(int max) { return rand() % max; }

int p5_constrain(int value,int min, int max) {
	if (value < min)
		return min;
	if (value > max)
		return max;
	return value;
}

void p5_strokeWeight(float weight) {
	_lineWidth = weight;
	glLineWidth(weight);
}

void p5_textAlign(int align) {
	_textAlign = align;
}

int p5_charWidth(char c) {
  return glutStrokeWidth(GLUT_STROKE_ROMAN, &c)*0.12f;
}

int p5_textWidth(char * text) {
  char *p;
  int length=0;
 
  for (p = text; *p; p++)
      length += glutStrokeWidth(GLUT_STROKE_ROMAN, *p);
  return length*0.12f;
}

void p5_textSize(float textSize) {
  _textRatio = textSize * 0.007f;
}

void p5_text(char * text, float x, float y) {
  char *p;
  int textWidth = p5_textWidth(text);  
	
  switch (_textAlign) {
	  case P5_CENTER:
	    x -= textWidth/2;
	    break;
	  case P5_RIGHT:
	    x -= textWidth;
	    break;
	  case P5_LEFT:
	    break;
  }

  glEnable(GL_LINE_SMOOTH);
  glLineWidth(_textRatio*13);
  glColor4f(_fill->red,_fill->green,_fill->blue,_fill->alpha);
  glPushMatrix();
  glTranslatef(x, y, 0);
  glScalef(_textRatio,-_textRatio,1.0f);
  for (p = text; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
  glPopMatrix();
  glLineWidth(_lineWidth);
  if (!_smoothFlag) glDisable(GL_LINE_SMOOTH);
}

float p5_map(float value, float istart, float istop, float ostart,
             float ostop) {
  return ostart + (ostop - ostart) * ((value - istart) / (istop - istart));
}

static void _reshape(int w, int h) {
  p5_width = w;
  p5_height = h;

  glViewport(0,0,(GLsizei)w,(GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, w, h, 0, -1, 1);
  //gluPerspective(45.0, (float)w/(float)h, 0.1f, 100.0f);
  glMatrixMode(GL_MODELVIEW);
  
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
}

void p5_size(float w, float h) {
  p5_width = w;
  p5_height = h;
  glutInitWindowSize(p5_width, p5_height);
  glutCreateWindow(title);
}

void p5_init(int argc, char **argv) {
  glutInit(&argc, argv); // Initialize GLUT
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  if (_setupDef)
    _setup();
  else {
    glutInitWindowSize(p5_width, p5_height);
    glutCreateWindow(title);
  }
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _fill = color_make(255,255,255,1);
  _stroke = color_make(0,0,0,1);
  glutSpecialFunc(_specialKeys);
  glutKeyboardFunc(_keyboard);
  glutMotionFunc(_mouseMotion);
  glutMouseFunc(_mouseButton);
  glutTimerFunc(1, _timer, 0);
  glutDisplayFunc(_display);
  glutReshapeFunc(_reshape);
  glutMainLoop();
}

#endif
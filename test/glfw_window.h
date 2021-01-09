#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

GLFWwindow *window;

void setup();

void draw();

void _resize(int w, int h) {
	glfwSetWindowSize(window, w, h);
}

void _setup() {
	setup();
}

void _draw() {
  int width, height;
  glfwGetFramebufferSize(window, &width, &height);
  glViewport(0, 0, width, height);
  draw();
  glfwSwapBuffers(window);
  glfwPollEvents();
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
	p5_motionEvent((int)xpos,(int)ypos);
}

int main() {

  if (!glfwInit())
    exit(EXIT_FAILURE);

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

  window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwSetCursorPosCallback(window, cursor_position_callback);

  glfwMakeContextCurrent(window);
  gladLoadGL();
  glfwSwapInterval(1);
	glfwSetWindowSize(window, 640, 480);

  p5_setupFunc(&_setup);
  p5_drawFunc(&_draw);
	//p5_resizeFunc(&_resize);

  p5_init(640, 480);
  p5_loop();
  p5_mainLoop();

  glfwDestroyWindow(window);

  glfwTerminate();
  exit(EXIT_SUCCESS);
}
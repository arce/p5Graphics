#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

GLFWwindow *window;

void setup();

void draw();

void _size(int w, int h) { glfwSetWindowSize(window, w, h); }

void _setup() { setup(); }

void _draw() {
  int width, height;
  glfwGetFramebufferSize(window, &width, &height);
  glViewport(0, 0, width, height);
  draw();
	glfwSwapBuffers(window);
  glfwPollEvents();
}

static void cursor_position_callback(GLFWwindow *window, double xpos,
                                     double ypos) {
  p5_motionEvent((int)xpos, (int)ypos);
}

void key_callback(GLFWwindow *window, int key, int scancode, int action,
                  int mods) {
  p5_keyPressedEvent(key, scancode);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
	int bttn;
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	switch (button) {
		case GLFW_MOUSE_BUTTON_RIGHT:
		bttn = P5_RIGHT;
		break;
		case GLFW_MOUSE_BUTTON_LEFT:
		bttn = P5_LEFT;
		break;
	}
  p5_mouseEvent(button, action, xpos, ypos);
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
	glfwSetMouseButtonCallback(window, mouse_button_callback);
  glfwSetKeyCallback(window, key_callback);

  glfwMakeContextCurrent(window);
  gladLoadGL();
  glfwSwapInterval(1);
  glfwSetWindowSize(window, 640, 480);

  p5_setupFunc(&_setup);
  p5_drawFunc(&_draw);
  p5_sizeFunc(&_size);

  p5_init(640, 480);
  p5_loop();
  p5_mainLoop();

  glfwDestroyWindow(window);

  glfwTerminate();
  exit(EXIT_SUCCESS);
}
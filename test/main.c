#include <glad/glad.h>
#include <p5Graphics.h>
#include <stdio.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

GLFWwindow *window;

static void key_callback(GLFWwindow *window, int key, int scancode, int action,
                         int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void setup() { printf("Setup\n"); }

void draw() {
  int width, height;
  glfwGetFramebufferSize(window, &width, &height);
  glViewport(0, 0, width, height);
  p5_background(0xAAAAAAFF);
	p5_rect(30, 20, 55, 55);
  glfwSwapBuffers(window);
  glfwPollEvents();
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

  glfwSetKeyCallback(window, key_callback);

  glfwMakeContextCurrent(window);
  gladLoadGL();
  glfwSwapInterval(1);
	glfwSetWindowSize(window, 640, 480);

  printf("Main\n");
  p5_setupFunc(&setup);
  p5_drawFunc(&draw);

  p5_init(640, 480);
  p5_loop();
  p5_mainLoop();

  glfwDestroyWindow(window);

  glfwTerminate();
  exit(EXIT_SUCCESS);
}
#include <stdio.h>
#include <p5Graphics.h>
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

GLFWwindow* window;
	
void setup() {
	printf("Setup\n");
}

void draw() {
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	p5_background(0xFFFFFFFF);
	p5_fill(0xAAAAAAFF);
	p5_line(10.0,10.0,20.0,20.0);
  glfwSwapBuffers(window);
  glfwPollEvents();
}

static void error_callback(int error, const char* description) {
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main() {
	glfwSetErrorCallback(error_callback);
  if (!glfwInit())
      exit(EXIT_FAILURE);

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

  window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
  if (!window)
  {
      glfwTerminate();
      exit(EXIT_FAILURE);
  }

  glfwSetKeyCallback(window, key_callback);

  glfwMakeContextCurrent(window);
  //gladLoadGL(glfwGetProcAddress);
	gladLoadGL();
  glfwSwapInterval(1);
	
	printf("Main\n");
	p5_setupFunc(&setup);
	p5_drawFunc(&draw);
	
	p5_init(640,480);
	p5_loop();
	p5_mainLoop();
}
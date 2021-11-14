
#define GLEW_STATIC
 

#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
using namespace glm;

int main() {

  // Initialise GLFW.
  if (!glfwInit()) {
    fprintf (stderr, "Failed to initialize GLFW\n");
    return -1;
  }

  // Create GLFW window.
  glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing.
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3.
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed.
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL.

  // Open a window and create its OpenGL context.
  GLFWwindow* window; // (In the accompanying source code, this variable is global for simplicity).
  window = glfwCreateWindow(800, 600, "GLX Window Example", NULL, NULL);
  if (window == NULL) {
    fprintf( stderr, "Failed to open GLFW window. Is your GPU GL-3.3 compatible?\n" );
    glfwTerminate();
    return -1;
  }
  glfwSetWindowOpacity(window, 0.5f);
  glfwMakeContextCurrent(window); // Initialize GLEW.

  // Ensure we can capture the escape key being pressed below.
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  do {
      // Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
      glClear(GL_COLOR_BUFFER_BIT);

      // Draw nothing, see you in tutorial 2!

      // Swap buffers
      glfwSwapBuffers(window);
      glfwPollEvents();

  } // Check if the ESC key was pressed or the window was closed.
  while (glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}

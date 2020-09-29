#include <gl_core_4_4.h>
#include <GLFW/glfw3.h>
#include <cstdio>

int main() {

	if (!glfwInit())
	{
		return -1;
	}

	//Game goes here

	GLFWwindow* window = glfwCreateWindow(1920, 1080, "Game",nullptr,nullptr );


	if (window == nullptr)
	{
		glfwTerminate();
		return -2;
	}

	glfwMakeContextCurrent(window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}

	int major = ogl_GetMajorVersion();
	int minor = ogl_GetMinorVersion();
	printf("OpenGL version: %i.%i\n", major, minor);

	//Loopgoes here
	while (!glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
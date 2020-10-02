#include "GraphicsApp.h"

#include <cstdio>




GraphicsApp::GraphicsApp()
{
	m_width = 1280;
	m_height = 720;
	m_title = "Computer Graphics";
}

GraphicsApp::GraphicsApp(int width, int height, const char* title)
{
	m_width = width;
	m_height = height;
	m_title = title;
}

bool GraphicsApp::start()
{
	using glm::vec3;
	using glm::vec4;
	using glm::mat4;

	if (!glfwInit())
	{
		return -1;
	}

	//Game goes here

	m_window = glfwCreateWindow(m_width, 1080, "Game", nullptr, nullptr);


	if (m_window == nullptr)
	{
		glfwTerminate();
		return -2;
	}

	glfwMakeContextCurrent(m_window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return -3;
	}

	int major = ogl_GetMajorVersion();
	int minor = ogl_GetMinorVersion();

	aie::Gizmos::create(10000, 10000, 10000, 10000);

	m_view = glm::lookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));
	m_projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.0f, 0.1f, 1000.0f);

	printf("OpenGL version: %i.%i\n", major, minor);

	glClearColor(0.05f, 0.05f, 0.025f, 1.0f);
}

bool GraphicsApp::update(double deltaTime)
{
	glfwPollEvents();

	if (!glfwWindowShouldClose(m_window) || !glfwGetKey(m_window, GLFW_KEY_ESCAPE))
	{
		return false;
	}

	return true;
	
}

bool GraphicsApp::draw()
{
	using glm::vec3;
	using glm::vec4;
	using glm::mat4;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	aie::Gizmos::clear();

	aie::Gizmos::addTransform(mat4(1));
	aie::Gizmos::draw(m_projection * m_view);

	glfwSwapBuffers(m_window);


	glfwTerminate();
	return 0;
}

bool GraphicsApp::end()
{
	return false;
}

bool GraphicsApp::run()
{
	bool updating = true;
	bool drawing = true;

	double deltaTime = 0.0f;
	double timeOfPreviousUpdate = 0.0f;

	if (!start())
	{
		return false;
	}
	while (updating && drawing)
	{
		double timeOfCurrentUpdate = glfwGetTime();

		deltaTime = timeOfCurrentUpdate - timeOfPreviousUpdate;

		timeOfPreviousUpdate = glfwGetTime();

		bool running = true;
		if (!start())
		{
			return -1;
		}

		while (running)
		{
			deltaTime = glfwGetTime();
			running = update(deltaTime);
			drawing = draw();
		}

		if (!end())
		{
			return -2;
		}
	}
}

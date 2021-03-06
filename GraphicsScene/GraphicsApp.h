#pragma once
#include <gl_core_4_4.h>
#include <GLFW/glfw3.h>
#include <Gizmos.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>


class GraphicsApp
{
public:
	GraphicsApp();
	GraphicsApp(int width, int height, const char* title);
	~GraphicsApp() {};

	bool start();
	bool update(double deltaTime);
	bool draw();
	bool end();
	bool run();

protected:
	GLFWwindow* m_window;
	glm::mat4 m_view;
	glm::mat4 m_projection;
	
private:
	int m_width;
	int m_height;
	const char* m_title;
};


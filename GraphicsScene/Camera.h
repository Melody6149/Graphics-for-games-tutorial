#pragma once
#include <glm/glm.hpp>
#include <gl_core_4_4.h>
#include <Gizmos.h>

class Camera
{
public:
	Camera() {}
	~Camera() {}

	glm::mat4 getViewMatrix();

	glm::mat4 getProjectionMatrix(float width, float height);

	float getYaw() { return m_yaw; }
	void setYaw(float degrees) { m_yaw = degrees; }
	float getPitch() { return m_pitch; }
	void setPitch(float dregrees) { m_pitch = dregrees; }


private:
	float m_yaw; 
	float m_pitch;
	glm::vec3 m_position;
};


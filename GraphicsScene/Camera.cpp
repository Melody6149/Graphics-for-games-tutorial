#include "Camera.h"
#include <glm/ext.hpp>

glm::mat4 Camera::getViewMatrix()
{
	float yawRadians = glm::radians(m_yaw);
	float pitchRadians = glm::radians(m_pitch);
	glm::vec3 forward(
		cos(pitchRadians) * cos(yawRadians),
		sin(pitchRadians),
		cos(pitchRadians) * sin(yawRadians));

	return glm::lookAt(m_position, m_position + forward, glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 Camera::getProjectionMatrix(float width, float height)
{
	return glm::perspective(glm::pi<float>() * 0.25, width / height, 0.1, 1000.0f);
}

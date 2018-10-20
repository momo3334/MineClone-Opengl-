#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/constants.hpp>
#include "Transform.h"
#include <vector>

class Camera {
public:
	Camera(const glm::vec3 pos, float fov, float aspect, float zNear, float zFar);

	glm::mat4 GetViewProjection() const;

	void Rotate(float relX, float relY);

	void Translate(char direction);


	void MoveFoward();
	void MoveBackward();
	void MoveStrafeLeft();
	void MoveStrafeRight();
	void MoveUp();
	void MoveDown();

	glm::vec3 m_Foward;
protected:
private:
	float m_Phi;
	float m_Theta;
	glm::vec3 m_Orientation;

	glm::vec3 m_Up;
	glm::vec3 m_Lateral_Translation;

	glm::vec3 m_Position;


	glm::mat4 m_Perspective;

	std::vector<float> m_OldMousePos;
};
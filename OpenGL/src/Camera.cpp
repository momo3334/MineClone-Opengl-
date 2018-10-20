#include "Camera.h"
#include <iostream>

float CAMERA_SPEED = 0.01f;

Camera::Camera(const glm::vec3 pos, float fov, float aspect, float zNear, float zFar) {
	m_Perspective = glm::perspective(fov, aspect, zNear, zFar);
	m_Position = pos;
	m_Foward = glm::vec3(0.0f, 0.0f, -1.0f);
	m_Up = glm::vec3(0.0f, 1.0f, 0.0f);
	m_Phi = 0;
	m_Theta = 0;
	m_OldMousePos = {0, 0};
}

glm::mat4 Camera::GetViewProjection() const
{
	return m_Perspective * (glm::lookAt(m_Position,m_Position + m_Foward, m_Up));
}

void Camera::Rotate(float relX, float relY)
{
	//relX = 0;

	
	//m_Theta += -relY * 0.00001f;

	//float M_PHI = glm::pi<float>();
	//float phiRadian = rel * M_PHI / 180;
	//float thetaRadian = relY * M_PHI / 180;

	///*ONLY WHEN Y AXIS IS UP*/
	//m_Orientation.x = cos(phiRadian) * sin(thetaRadian);
	//m_Orientation.y = sin(phiRadian);
	//m_Orientation.z = cos(phiRadian) * cos(thetaRadian);
	////m_Orientation = glm::normalize(m_Orientation);

	///*Calculation of normal*/
	//m_Lateral_Translation = glm::cross(m_Up, m_Orientation);
	//m_Lateral_Translation = glm::normalize(m_Lateral_Translation);

	/*Adjusting Foward vector to be straight in front of camera*/
	

	float deltaX = m_OldMousePos.at(0) - relX * 0.001f;
	float deltaY = m_OldMousePos.at(1) - relY * 0.001f;

	std::cout <<  acos((float)glm::dot(m_Position, glm::vec3(0.0f, 1.0f, 0.0f))) << std::endl;
	//std::cout << m_Phi << std::endl;

	if (m_Phi >= 89.0)
		deltaX = 89.0;
	if (m_Theta >= 89.0)
		deltaY = 89.0;


	glm::vec3 rotateAround = glm::cross(m_Foward, m_Up);
	glm::mat4 rotationMatrix = (glm::mat4(glm::rotate(deltaX, m_Up))) * (glm::mat4(glm::rotate(deltaY, rotateAround)));

	m_Foward = glm::mat3(rotationMatrix) * m_Foward;
		m_OldMousePos = { relX * 0.001f, relY * 0.001f };
}

void Camera::MoveFoward()
{
	m_Position += CAMERA_SPEED * m_Foward;
}

void Camera::MoveBackward()
{
	m_Position += -CAMERA_SPEED * m_Foward;
}

void Camera::MoveStrafeLeft()
{
	glm::vec3 strafeDirection = glm::cross(m_Foward, m_Up);
	m_Position += -CAMERA_SPEED * strafeDirection;
}

void Camera::MoveStrafeRight()
{
	glm::vec3 strafeDirection = glm::cross(m_Foward, m_Up);
	m_Position += CAMERA_SPEED * strafeDirection;
}

void Camera::MoveUp()
{
	m_Position += CAMERA_SPEED * m_Up;
}

void Camera::MoveDown()
{
	m_Position += -CAMERA_SPEED * m_Up;
}

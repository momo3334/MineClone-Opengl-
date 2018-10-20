#include "Input.h"
#include <iostream>

Input::Input() : m_MouseX(0), m_MouseY(0), m_RelMouseX(0), m_RelMouseY(0), m_CloseWindow(false)
{
	/*Setting keys array to false*/
	for (unsigned int i = 0; i < GLFW_KEY_LAST + 1 ; i++)
	{
		m_Keys[i] = false;
	}

	/*Setting mouse buttons array to false*/
	for (unsigned int i = 0; i < GLFW_KEY_LAST + 1; i++)
	{
		m_MouseButtons[i] = false;
	}
}

Input::~Input()
{

}

void Input::updateKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS))
	{
		std::cout << key << std::endl;
	}
}

void Input::updateMouse()
{

}

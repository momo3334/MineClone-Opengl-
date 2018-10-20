#pragma once

#include "GLFW/glfw3.h"


class Input {
public:
	Input();
	~Input();


	void updateKeyboard(GLFWwindow * window, int key, int scancode, int action, int mods);
	void updateMouse();

protected:
private:
	bool m_Keys[GLFW_KEY_LAST + 1];
	bool m_MouseButtons[GLFW_MOUSE_BUTTON_LAST + 1];

	bool m_CloseWindow;

	int m_MouseX;
	int m_MouseY;

	int m_RelMouseX;
	int m_RelMouseY;
};
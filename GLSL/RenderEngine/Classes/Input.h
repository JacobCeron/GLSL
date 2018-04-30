#pragma once

#include "Window.h"

enum KeyCode
{
	UpArrow = GLFW_KEY_UP,
	DownArrow = GLFW_KEY_DOWN,
	RightArrow = GLFW_KEY_RIGHT,
	LeftArrow = GLFW_KEY_LEFT,
	A = GLFW_KEY_A,
	D = GLFW_KEY_D,
	W = GLFW_KEY_W,
	S = GLFW_KEY_S,
	Space = GLFW_KEY_SPACE,
	Esc = GLFW_KEY_ESCAPE,
	Enter = GLFW_KEY_ENTER
};

class Input
{
public:
	static Vector2 mousePosition;
private:
	static GLFWwindow* m_window;

public:
	static bool getKey(KeyCode key);

	friend class Window;
};
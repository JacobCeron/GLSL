#include "Input.h"

Vector2 Input::mousePosition(0.0f, 0.0f);
GLFWwindow* Input::m_window{ nullptr };

bool Input::getKey(KeyCode key)
{
	return (glfwGetKey(Input::m_window, key) == GLFW_PRESS);
}
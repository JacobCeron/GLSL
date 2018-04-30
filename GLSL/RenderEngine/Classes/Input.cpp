#include "Input.h"

Vector2 Input::mousePosition;
GLFWwindow* Input::m_window{ nullptr };

bool Input::getKey(KeyCode key)
{
	return (glfwGetKey(Input::m_window, key) == GLFW_PRESS);
}
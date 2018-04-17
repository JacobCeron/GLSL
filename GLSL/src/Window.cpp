#include <glad\glad.h>
#include "Window.h"

Window* Window::window = nullptr;

Window::Window()
{
}

void Window::init()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

bool Window::createWindow(int width, int height, const char* name)
{
	init();
	m_window = glfwCreateWindow(width, height, name, nullptr, nullptr);

	if (m_window == nullptr)
		return false;
	glfwMakeContextCurrent(m_window);
	glfwSetFramebufferSizeCallback(m_window, framebufferSizeCallback);
	glfwSetCursorPosCallback(m_window, cursorPosCallback);
	return true;
}

bool Window::initGL()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return false;
	return true;
}

bool Window::closeWindow()
{
	return glfwWindowShouldClose(m_window);
}

void Window::SwapImageBuffers()
{
	glfwSwapBuffers(m_window);
}

void Window::PollEvents()
{
	glfwPollEvents();
}

void Window::windowCallbacks(Window* w)
{
	window = w;
}

void Window::resize(int w, int h)
{
	m_width = w;
	m_height = h;
}

void Window::cursorPos(double x, double y)
{
	m_xPos = x;
	m_yPos = y;
}

int Window::getWidth()
{
	return m_width;
}

int Window::getHeight()
{
	return m_height;
}

double Window::getXPos()
{
	return m_xPos;
}

double Window::getYPos()
{
	return m_yPos;
}

void Window::framebufferSizeCallback(GLFWwindow* w, int width, int height)
{
	window->resize(width, height);
}

void Window::cursorPosCallback(GLFWwindow* w, double xPos, double yPos)
{
	window->cursorPos(xPos, yPos);
}

Window::~Window()
{
	glfwTerminate();
}

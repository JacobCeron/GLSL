#include <glad\glad.h>
#include "Window.h"
#include "Input.h"

Window* Window::window{ nullptr };
int Window::s_width{ 0 };
int Window::s_height{ 0 };

Window::Window(int width, int height, const char* name)
	: m_width{ width }, m_height{ height }, m_name{ name }
{
	s_width = m_width;
	s_height = m_height;
}

void Window::init()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif // __APPLE__

}

bool Window::createWindow()
{
	init();
	m_window = glfwCreateWindow(m_width, m_height, m_name, nullptr, nullptr);

	if (m_window == nullptr)
		return false;
	glfwMakeContextCurrent(m_window);
	glfwSetFramebufferSizeCallback(m_window, framebufferSizeCallback);
	glfwSetCursorPosCallback(m_window, cursorPosCallback);

	//glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	Input::m_window = m_window;

	return true;
}

bool Window::initGL()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return false;
	return true;
}

void Window::enableBuffers()
{
	glEnable(GL_DEPTH_TEST);
}

bool Window::closeWindow()
{
	return glfwWindowShouldClose(m_window);
}

void Window::color(const Vector3& color)
{
	glClearColor(color.r, color.g, color.b, 1.0f);
}

void Window::clearBuffers()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
	s_width = width;
	s_height = height;
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

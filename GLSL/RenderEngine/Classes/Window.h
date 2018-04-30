#pragma once

#include <GLFW\glfw3.h>
#include "Maths.h"

class Window
{
private:
	GLFWwindow * m_window;
	int m_width;
	int m_height;
	double m_xPos;
	double m_yPos;
	const char* m_name;
	static Window* window;

public:
	Window(int width, int height, const char* name);
	void init();
	bool createWindow();
	bool initGL();
	void enableBuffers();
	bool closeWindow();
	void color(const Vector3& color);
	void clearBuffers();
	void SwapImageBuffers();
	void PollEvents();
	void windowCallbacks(Window* w);
	void resize(int w, int h);
	void cursorPos(double x, double y);
	int getWidth();
	int getHeight();
	double getXPos();
	double getYPos();
	~Window();

	static void framebufferSizeCallback(GLFWwindow* w, int width, int height);
	static void cursorPosCallback(GLFWwindow* w, double xPos, double yPos);
};

#include "Application.h"
#include "Time.h"

Application::Application()
{
}

void Application::run(Application& app)
{
	if (m_window.createWindow(666, 600, "OpenGL"))
	{
		m_window.windowCallbacks(&m_window);
		if (m_window.initGL())
		{
			app.Start();

			float lastFrame{ 0.0f };

			while (!m_window.closeWindow())
			{
				glViewport(0, 0, m_window.getWidth(), m_window.getHeight());

				float currentFrame{ static_cast<float>(glfwGetTime()) };
				Time::deltaTime = currentFrame - lastFrame;
				lastFrame = currentFrame;

				app.Update();

				m_window.SwapImageBuffers();
				m_window.PollEvents();
			}
		}
	}
}

Application::~Application()
{
}
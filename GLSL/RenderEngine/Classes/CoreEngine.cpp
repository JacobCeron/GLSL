#include "CoreEngine.h"
#include "Time.h"

CoreEngine::CoreEngine(int width, int height, const char* name)
	: m_window(width, height, name)
{}

void CoreEngine::run(CoreEngine& app)
{
	if (m_window.createWindow())
	{
		m_window.windowCallbacks(&m_window);
		if (m_window.initGL())
		{
			app.Start();

			float lastFrame{ 0.0f };

			m_window.enableBuffers();

			while (!m_window.closeWindow())
			{
				m_window.clearBuffers();
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

CoreEngine::~CoreEngine()
{
}
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
			rendererEngine.InitMeshRenderer();

			float lastFrame{ 0.0f };

			m_window.enableBuffers();

			while (!m_window.closeWindow())
			{
				float currentFrame{ static_cast<float>(glfwGetTime()) };
				Time::deltaTime = currentFrame - lastFrame;
				lastFrame = currentFrame;

				Input::mousePosition.x = m_window.getXPos();
				Input::mousePosition.y = m_window.getYPos();

				m_window.color(Vector3(0.1921f, 0.3019f, 0.4745f));
				m_window.clearBuffers();
				glViewport(0, 0, m_window.getWidth(), m_window.getHeight());

				app.Update();
				rendererEngine.Renderer();

				m_window.SwapImageBuffers();
				m_window.PollEvents();
			}
		}
	}
}

CoreEngine::~CoreEngine()
{
}
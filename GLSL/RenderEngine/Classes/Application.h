#pragma once

#include "Window.h"

class Application
{
public:
	Window m_window;

public:
	Application();
	void run(Application& app);
	virtual void Start() = 0;
	virtual void Update() = 0;
	~Application();
};
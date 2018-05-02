#pragma once

#include "Window.h"
#include "RendererEngine.h"

class CoreEngine
{
public:
	Window m_window;
	RendererEngine rendererEngine;

public:
	CoreEngine(int width, int height, const char* name);
	void run(CoreEngine& app);
	virtual void Start() = 0;
	virtual void Update() = 0;
	~CoreEngine();
};
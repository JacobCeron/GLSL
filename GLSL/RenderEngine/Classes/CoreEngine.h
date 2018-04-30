#pragma once

#include "Window.h"

class CoreEngine
{
public:
	Window m_window;

public:
	CoreEngine(int width, int height, const char* name);
	void run(CoreEngine& app);
	virtual void Start() = 0;
	virtual void Update() = 0;
	~CoreEngine();
};
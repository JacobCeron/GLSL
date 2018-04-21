#pragma once

#include <vector>
#include "Vector.h"

class Mesh
{
public:
	std::vector<Vector<float, 3>> position;
	std::vector<Vector<float, 2>> uv;
	std::vector<Vector<float, 3>> normal;

	std::vector<Vector<unsigned int, 4>> indexPosition;

public:
	Mesh();
	void loadModel(const char* fileName);
	~Mesh();
};

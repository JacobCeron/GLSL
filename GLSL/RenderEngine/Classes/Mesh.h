#pragma once

#include <vector>
#include "Maths.h"
#include "Vector.h"

class Mesh
{
public:
	std::vector<Vector3> position;
	std::vector<Vector2> uv;
	std::vector<Vector3> normal;

	std::vector<Vector3ui> index;

public:
	Mesh();
	void loadModel(const char* fileName);
	~Mesh();
};

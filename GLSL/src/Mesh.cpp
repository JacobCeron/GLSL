#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

#include <iostream>

#include "Mesh.h"

Mesh::Mesh()
{
}

// .OBJ loader
void Mesh::loadModel(const char* fileName)
{
	std::ifstream file(fileName);

	if (!file)
		return;

	std::string line;

	while (std::getline(file, line))
	{
		if (line.substr(0, 2) == "v ")
		{
			std::stringstream text(line.substr(2, line.size()));
			Vector<float, 3> v;
			for (size_t i{ 0 }; i < v.size(); i++)
				text >> v[i];
			position.push_back(v);
		}
		else if (line.substr(0, 3) == "vt ")
		{
			std::stringstream text(line.substr(3, line.size()));
			Vector<float, 2> vt;
			for (size_t i{ 0 }; i < vt.size(); i++)
				text >> vt[i];
			uv.push_back(vt);
		}
		else if (line.substr(0, 3) == "vn ")
		{
			std::stringstream text(line.substr(3, line.size()));
			Vector<float, 3> vn;
			for (size_t i{ 0 }; i < vn.size(); i++)
				text >> vn[i];
			normal.push_back(vn);
		}
		else if (line.substr(0, 2) == "f ")
		{
			std::stringstream text(line.substr(2, line.size()));
			std::string word;
			Vector<unsigned int, 4> iv;
			size_t count{ 0 };
			while (text >> word)
			{
				std::stringstream ss(word);
				ss >> iv[count];
				iv[count++] -= 1;
			}
			indexPosition.push_back(iv);
		}
	}

	for (size_t i{ 0 }; i < indexPosition.size(); i++)
	{
		unsigned int temp{ indexPosition[i][indexPosition[0].size() - 2] };
		indexPosition[i][indexPosition[0].size() - 2] = indexPosition[i][indexPosition[0].size() - 1];
		indexPosition[i][indexPosition[0].size() - 1] = temp;
	}
}

Mesh::~Mesh()
{
}

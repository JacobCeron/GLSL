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

	if (!position.empty())
		position.clear();
	if (!uv.empty())
		uv.clear();
	if (!normal.empty())
		normal.clear();
	if (!index.empty())
		index.clear();

	std::string line;

	std::vector<Vector3> vV;
	std::vector<Vector2> vVT;
	std::vector<Vector3> vVN;

	std::vector<Vector4ui> indexPosition;
	std::vector<Vector4ui> indexUV;
	std::vector<Vector4ui> indexNormal;

	while (std::getline(file, line))
	{
		if (line.substr(0, 2) == "# ")
		{
			continue;
		}
		else if (line.substr(0, 2) == "v ")
		{
			std::stringstream text(line.substr(2, line.size()));
			Vector3 v;
			for (size_t i{ 0 }; i < Vector3::size; i++)
				text >> v[i];
			vV.push_back(v);
		}
		else if (line.substr(0, 3) == "vt ")
		{
			std::stringstream text(line.substr(3, line.size()));
			Vector2 vt;
			for (size_t i{ 0 }; i < Vector2::size; i++)
				text >> vt[i];
			vVT.push_back(vt);
		}
		else if (line.substr(0, 3) == "vn ")
		{
			std::stringstream text(line.substr(3, line.size()));
			Vector3 vn;
			for (size_t i{ 0 }; i < Vector3::size; i++)
				text >> vn[i];
			vVN.push_back(vn);
		}
		else if (line.substr(0, 2) == "f ")
		{
			std::stringstream text(line.substr(2, line.size()));
			std::string word;
			Vector4ui iv;
			Vector4ui ivt;
			Vector4ui ivn;
			size_t count{ 0 };
			while (text >> word)
			{
				std::replace(word.begin(), word.end(), '/', ' ');
				std::stringstream ss(word);
				ss >> iv[count];
				iv[count] -= 1;
				ss >> ivt[count];
				ivt[count] -= 1;
				ss >> ivn[count];
				ivn[count] -= 1;
				count++;
			}
			indexPosition.push_back(iv);
			indexUV.push_back(ivt);
			indexNormal.push_back(ivn);
		}
	}

	for (size_t i{ 0 }; i < indexPosition.size(); i++)
		for (size_t j{ 0 }; j < Vector4ui::size; j++)
			position.push_back(vV[indexPosition[i][j]]);

	for (size_t i{ 0 }; i < indexUV.size(); i++)
		for (size_t j{ 0 }; j < Vector4ui::size; j++)
			uv.push_back(vVT[indexUV[i][j]]);

	for (size_t i{ 0 }; i < indexNormal.size(); i++)
		for (size_t j{ 0 }; j < Vector4ui::size; j++)
			normal.push_back(vVN[indexNormal[i][j]]);

	size_t j{ 0 };
	for (size_t i{ 0 }; i < indexPosition.size(); i++)
	{
		Vector3ui iPos;
		size_t count{ 0 };
		size_t size{ j + Vector3ui::size };
		for (; j < size; j++)
			iPos[count++] = j;
		j -= 1;
		index.push_back(iPos);

		count = 0;
		size = j + Vector3ui::size;
		for (; j < size; j++)
		{
			if (j == size - 1)
				iPos[count] = j - 4;
			else
				iPos[count++] = j;
		}
		j -= 1;
		index.push_back(iPos);
	}
}

Mesh::~Mesh()
{
}

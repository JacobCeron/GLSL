#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

#include "Mesh.h"

#include <iostream>

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

	std::vector<Vector<float, 3>> vV;
	std::vector<Vector<float, 2>> vVT;
	std::vector<Vector<float, 3>> vVN;

	while (std::getline(file, line))
	{
		if (line.substr(0, 2) == "v ")
		{
			std::stringstream text(line.substr(2, line.size()));
			Vector<float, 3> v;
			for (size_t i{ 0 }; i < v.size(); i++)
				text >> v[i];
			vV.push_back(v);
		}
		else if (line.substr(0, 3) == "vt ")
		{
			std::stringstream text(line.substr(3, line.size()));
			Vector<float, 2> vt;
			for (size_t i{ 0 }; i < vt.size(); i++)
				text >> vt[i];
			vVT.push_back(vt);
		}
		else if (line.substr(0, 3) == "vn ")
		{
			std::stringstream text(line.substr(3, line.size()));
			Vector<float, 3> vn;
			for (size_t i{ 0 }; i < vn.size(); i++)
				text >> vn[i];
			vVN.push_back(vn);
		}
		else if (line.substr(0, 2) == "f ")
		{
			std::stringstream text(line.substr(2, line.size()));
			std::string word;
			Vector<int, 4> iv;
			Vector<int, 4> ivt;
			Vector<int, 4> ivn;
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
	{
		int tempV{ indexPosition[i][indexPosition[0].size() - 2] };
		indexPosition[i][indexPosition[0].size() - 2] = indexPosition[i][indexPosition[0].size() - 1];
		indexPosition[i][indexPosition[0].size() - 1] = tempV;

		int tempVT{ indexUV[i][indexUV[0].size() - 2] };
		indexUV[i][indexUV[0].size() - 2] = indexUV[i][indexUV[0].size() - 1];
		indexUV[i][indexUV[0].size() - 1] = tempVT;

		int tempVN{ indexNormal[i][indexNormal[0].size() - 2] };
		indexNormal[i][indexNormal[0].size() - 2] = indexNormal[i][indexNormal[0].size() - 1];
		indexNormal[i][indexNormal[0].size() - 1] = tempVN;
	}

	for (size_t i{ 0 }; i < indexPosition.size(); i++)
		for (size_t j{ 0 }; j < indexPosition[0].size(); j++)
			position.push_back(vV[indexPosition[i][j]]);

	for (size_t i{ 0 }; i < indexUV.size(); i++)
		for (size_t j{ 0 }; j < indexUV[0].size(); j++)
			uv.push_back(vVT[indexUV[i][j]]);

	for (size_t i{ 0 }; i < indexNormal.size(); i++)
		for (size_t j{ 0 }; j < indexNormal[0].size(); j++)
			normal.push_back(vVN[indexNormal[i][j]]);

	size_t count{ 0 };
	for (size_t i{ 0 }; i < indexPosition.size(); i++)
		for (size_t j{ 0 }; j < indexPosition[0].size(); j++)
			indexPosition[i][j] = count++;
}

Mesh::~Mesh()
{
}

#include <fstream>
#include <sstream>
#include <string>

#include "Mesh.h"

Mesh::Mesh()
{
}

void Mesh::loadModel(const char* fileName)
{
	std::ifstream file(fileName);

	if (!file)
		return;

	std::stringstream text;
	text << file.rdbuf();
	std::string word;

	while (text >> word)
	{
		if (word == "v")
		{
			Vector<float, 3> v;
			for (size_t i{ 0 }; i < v.size(); i++)
				text >> v[i];
			position.push_back(v);
		}
		else if (word == "vt")
		{
			Vector<float, 2> vt;
			for (size_t i{ 0 }; i < vt.size(); i++)
				text >> vt[i];
			uv.push_back(vt);
		}
		else if (word == "vn")
		{
			Vector<float, 3> vn;
			for (size_t i{ 0 }; i < vn.size(); i++)
				text >> vn[i];
			normal.push_back(vn);
		}
		else if (word == "f")
		{
			Vector<unsigned int, 3> iv;
			Vector<unsigned int, 3> ivt;
			Vector<unsigned int, 3> ivn;
			for (size_t i{ 0 }; i < 3; i++)
			{
				text >> word;
				switch (word.size())
				{
				case 1:
					iv[i] = static_cast<unsigned int>(word[0] - 49);
					break;
				case 3:
					iv[i] = static_cast<unsigned int>(word[0] - 49);
					ivt[i] = static_cast<unsigned int>(word[2] - 49);
					break;
				case 4:
					iv[i] = static_cast<unsigned int>(word[0] - 49);
					ivn[i] = static_cast<unsigned int>(word[3] - 49);
					break;
				case 5:
					iv[i] = static_cast<unsigned int>(word[0] - 49);
					ivt[i] = static_cast<unsigned int>(word[2] - 49);
					ivn[i] = static_cast<unsigned int>(word[4] - 49);
					break;
				}
			}
			indicesPosition.push_back(iv);
			indicesUV.push_back(ivt);
			indicesNormal.push_back(ivn);
		}
	}
}

Mesh::~Mesh()
{
}

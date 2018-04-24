#include "Classes\MyApplication.h"

#include "Classes\Maths.h"

#include <iostream>
#include <glm\gtc\matrix_transform.hpp>

int main()
{
	Matrix4x4 M;
	M = Matrix4x4::scale(M, Vector3(6));
	std::cout << M << std::endl;

	glm::mat4 m;
	m = glm::scale(m, glm::vec3(6));

	for (size_t i{ 0 }; i < 4; i++)
	{
		for (size_t j{ 0 }; j < 4; j++)
		{
			std::cout << m[i][j] << " ";
		}
		std::cout << "\n";
	}

	system("PAUSE");
	/*MyApplication app;
	app.run(app);*/

	return 0;
}
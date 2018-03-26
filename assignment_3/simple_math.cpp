#include "simple_math.h"
#define _USE_MATH_DEFINES
#include <math.h>

float SimpleMath::Degree2Radian(float degree) {
	return ((float)M_PI / 180.0f) * degree;
}

glm::mat3 SimpleMath::GetMat3RotationMatrix(glm::vec3 point, float radian)
{
	glm::mat3 rotation_matrix = {
		{ point.x * cosf(radian), -point.y * sinf(radian), 0.0f },
		{ point.x * sinf(radian), point.y * cosf(radian), 0.0f },
		{ 0.0f, 0.0f, 1.0f }
	};

	return rotation_matrix;
}
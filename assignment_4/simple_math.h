#pragma once
#ifndef SIMPLE_MATH_H_
#define SIMPLE_MATH_H_

#define _USE_MATH_DEFINES
#include <math.h>
#include <glm/mat3x3.hpp>

struct SimpleMath {
public:
	static float Degree2Radian(float degree);
	static glm::mat3 GetRotationMatrix(glm::vec3 point, float degree);
};

#endif // !SIMPLE_MATH_H_
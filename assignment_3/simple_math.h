#pragma once
#ifndef SIMPLE_MATH_H_
#define SIMPLE_MATH_H_

#define _USE_MATH_DEFINES
#include <math.h>

struct SimpleMath {
public:
	static float Degree2Radian(float degree) {
		return ((float)M_PI / 180.0f) * degree;
	}
};

#endif // !SIMPLE_MATH_H_
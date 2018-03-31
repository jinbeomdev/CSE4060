#pragma once
#ifndef PLANET_H_
#define PLANET_H_

#include <GLFW\glfw3.h>
#include <glm\mat4x4.hpp>
#include <glm\mat3x3.hpp>
#include <glm\vec3.hpp>
#include "simple_math.h"
#include <vector>

class planet {
public:
	planet(float radius);
	void DrawPlanet();
	void SetColor(float r, float g, float b);
	void SetRotationDegree(float degree);
	void SetTranslateVector(glm::vec3);
	void SetMoon(planet &moon);

private:
	float radius_;
	std::vector<glm::vec3> vertices_;

	float rotation_degree_;
	float current_rotation_degree_;

	float r_;
	float g_;
	float b_;

	glm::vec3 translate_vector_;

	void SetVertice();
};

#endif // ! PLANET_H_
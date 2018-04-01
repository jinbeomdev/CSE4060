#pragma once
#ifndef PLANET_H_
#define PLANET_H_

#include <GLFW\glfw3.h>
#include <glm\mat4x4.hpp>
#include <glm\mat3x3.hpp>
#include <glm\vec3.hpp>
#include "simple_math.h"
#include <vector>

class Planet {
public:
	Planet(float radius, float distance,
		     float revolution_degree, float rotation_degree,
		     float r, float g, float b);
	void DrawPlanet();
	void AddMoon(Planet &moon);

private:
	float radius_;
	float distance_;
	float revolution_degree_;
	float current_revolution_degree_;
	float rotation_degree_;
	float current_rotation_degree_;

	std::vector<glm::vec3> vertices_;

	/* color */
	float r_;
	float g_;
	float b_;

	/* moons */
	std::vector<Planet> moons_;

	/* functions */
	void SetVertice();
};

#endif // ! PLANET_H_
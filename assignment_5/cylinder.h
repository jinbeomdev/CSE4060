#pragma once
#ifndef CYLINDER_H_
#define CYLINDER_H_

#include "GLFW\glfw3.h"
#include "glm\vec3.hpp"
#include "simple_math.h"
#include <vector>

class Cylinder {
public:
	Cylinder(const float radius, const float height) : radius_(radius), height_(height) {};
	void Draw();
private:
	float radius_;
	float height_;
	std::vector<glm::vec3> top_vertices_;
	std::vector<glm::vec3> bottom_vertices_;
	
	void DrawCircle(const float height, const float noraml, std::vector<glm::vec3> &vertices);
	void DrawCylinder();
};

#endif // !CYLINDER_H_

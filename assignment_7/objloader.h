#pragma once
#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <vector>
#include <glm/glm.hpp>

bool loadOBJ(
	const char * path,
	std::vector<float> & out_vertices,
	std::vector<float> & out_normals
);

#endif // !OBJLOADER_H
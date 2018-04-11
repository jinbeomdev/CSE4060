#pragma once
#ifndef TETRAHEDRON_H_
#define TETRAHEDRON_H_

#include <GLFW\glfw3.h>

class tetrahedron {
public:
	void Draw();
	void DrawTetrahedron();
	void DrawAxes();

private:
	static const GLfloat vertices_[][3];
	static const GLint    indices_[][3];
	static const GLfloat   colors_[][3];
};
#endif // !TETRAHEDRON_H_

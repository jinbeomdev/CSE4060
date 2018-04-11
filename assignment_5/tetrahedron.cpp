#include "tetrahedron.h"

const GLfloat tetrahedron::vertices_[][3] = {
	{ -0.5f, -0.5f, -0.5f },
	{ 0.5f, -0.5f, -0.5f },
	{ 0.0f, -0.5f,  0.5f },
	{ 0.0f,  0.5f,  0.0f }
};

const GLint tetrahedron::indices_[][3] = {
	{ 0, 2, 1 },
	{ 0, 2, 3 },
	{ 1, 0, 3 },
	{ 2, 1, 3 }
};

const GLfloat tetrahedron::colors_[][3] = {
	{ 1.0f, 0.0f, 0.0f },  // red
	{ 1.0f, 1.0f, 0.0f },  // yellow
	{ 0.0f, 1.0f, 0.0f },  // green
	{ 0.0f, 0.0f, 1.0f }  // blue
};

void tetrahedron::Draw() {
	glEnable(GL_DEPTH_TEST);
	glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
	glPushMatrix();
	glRotatef(-15.0f, 1.0f, 0.0f, 0.0f);
	DrawTetrahedron();
	glPopMatrix();
	glDisable(GL_DEPTH_TEST);
}

void tetrahedron::DrawTetrahedron() {
	glBegin(GL_TRIANGLES);

	for (int i = 0; i < 4; i++) {
		glColor3fv(colors_[i]);

		for (int j = 0; j < 3; j++) {
			glVertex3fv(&vertices_[indices_[i][j]][0]);
		}
	}

	glEnd();
}

void tetrahedron::DrawAxes() {
	for (float i = 0.0f; i < 1.0f; i += 1.0f / 256.0f) {

	}
}
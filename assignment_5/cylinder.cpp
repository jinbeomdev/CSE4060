#include "cylinder.h"

void Cylinder::Draw() {
	glRotatef(10.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	DrawCircle(-height_, 1.0f, bottom_vertices_);
	glColor3f(0.0f, 1.0f, 0.0f);
	DrawCircle(height_, -1.0f, top_vertices_);
	glColor3f(0.0f, 0.0f, 1.0f);
	DrawCylinder();
}

void Cylinder::DrawCircle(const float height, const float noraml, std::vector<glm::vec3> &vertices) {
	const glm::vec3 start_point(radius_, 0.0f, height);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0f, 0.0f, height);
	for (float degree = -180.0f; degree <= 180.0f; degree += 1.0f / 256.0f) {
		const glm::mat3 rotation_matrix = 
			glm::transpose(SimpleMath::GetRotationMatrix(start_point, degree));
		const glm::vec3 point = rotation_matrix * start_point;
		vertices.push_back(point);
		glVertex3f(point.x, point.y, point.z);
	}
	glEnd();
}

void Cylinder::DrawCylinder() {
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < top_vertices_.size(); i++) {
		glVertex3fv(&top_vertices_[i][0]);
		glVertex3fv(&bottom_vertices_[i][0]);
	}
	glEnd();
}

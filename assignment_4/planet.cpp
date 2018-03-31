#include "planet.h"

planet::planet(const float radius) {
	radius_ = radius;
	rotation_degree_ = 0.0f;
	current_rotation_degree_ = 0.0f;

	SetVertice();
}

void planet::DrawPlanet() {
	current_rotation_degree_ = (current_rotation_degree_ + rotation_degree_);

	glColor3f(r_, g_, b_);

	glPushMatrix();
	glTranslatef(translate_vector_.x, translate_vector_.y, translate_vector_.z);
	glRotatef(current_rotation_degree_, 0.0f, 0.0f, 1.0f);
	
	glBegin(GL_TRIANGLE_FAN);
	for (glm::vec3 vertex : vertices_) {
		glVertex3f(vertex.x, vertex.y, vertex.z);
	}
	glEnd();

	glPopMatrix();
}

void planet::SetVertice() {
	const glm::vec3 start_point = { radius_, 0.0f, 0.0f };

	vertices_.push_back(glm::vec3(0.0f, 0.0f, 0.0f)); //center point of the planet

	for (float degree = 0.0f; degree <= 360.0f; degree += 45.0f) {
		const glm::mat3 rotation_matrix =
			glm::transpose(SimpleMath::GetRotationMatrix(start_point, degree));
		const glm::vec3 point = rotation_matrix * start_point;
		vertices_.push_back(point);
	}
}

void planet::SetColor(float r, float g, float b) {
	r_ = r; g_ = g; b_ = b;
}

void planet::SetRotationDegree(float degree) {
	rotation_degree_ = degree;
}

void planet::SetTranslateVector(glm::vec3 translate_vector) {
	translate_vector_ = translate_vector;
}
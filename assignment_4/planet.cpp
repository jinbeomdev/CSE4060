#include "planet.h"

Planet::Planet(float radius, float distance,
	             float revolution_degree, float rotation_degree,
	             float r, float g, float b) {
	radius_ = radius;
	distance_ = distance;
	revolution_degree_ = revolution_degree;
	current_revolution_degree_ = 0.0f;
	rotation_degree_ = rotation_degree;
	current_rotation_degree_ = 0.0f;

	r_ = r;
	g_ = g;
	b_ = b;

	SetVertice();
}

void Planet::DrawPlanet() {
	current_rotation_degree_ += rotation_degree_;
	current_revolution_degree_ += revolution_degree_;
	glColor3f(r_, g_, b_);

	glPushMatrix(); // 1
	glTranslatef(distance_, 0.0f, 0.0f);
	glRotatef(current_revolution_degree_, 0.0f, 0.0f, 1.0f);
	
	/* Redering Planet */
	glPushMatrix(); // 2
	glRotatef(current_rotation_degree_, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
	for (glm::vec3 vertex : vertices_) {
		glVertex3f(vertex.x, vertex.y, vertex.z);
	}
	glEnd();
	glPopMatrix(); // -2

	/* Redering moons */
	for (Planet &moon : moons_) {
		moon.DrawPlanet();
	}
	glPopMatrix(); // -1
}

void Planet::SetVertice() {
	const glm::vec3 start_point = { radius_, 0.0f, 0.0f };

	vertices_.push_back(glm::vec3(0.0f, 0.0f, 0.0f)); //center point of the planet

	for (float degree = 0.0f; degree <= 360.0f; degree += 45.0f) {
		const glm::mat3 rotation_matrix =
			glm::transpose(SimpleMath::GetRotationMatrix(start_point, degree));
		const glm::vec3 point = rotation_matrix * start_point;
		vertices_.push_back(point);
	}
}

void Planet::AddMoon(Planet &moon) {
	moons_.push_back(moon);
}

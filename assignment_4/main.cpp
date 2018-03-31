/*
Lab 4. Animate the solar system

Animate Earth, Moon, and Sun in 2D, similarly to the example from the lecture.
Notes:
1. render Earth, Moon and Sun (4 point)
2. rotation of Earth, Moon and Sun (2 point)
3. revolving Earth around Sun (2 point)
4. revolving Moon around Earth (2 point)
You do not have to calculate it perfectly.
*/

#include "glfw_session.h"
#include "planet.h"
#include <vector>

int main() {
	GLFWSession glfw_session;
	std::vector<planet> planets;

	planet sun(0.6f);
	sun.SetColor(1.0f, 0.0f, 0.0f);
	sun.SetRotationDegree(10.0f);
	planets.push_back(sun);

	planet earth(0.4f);
	earth.SetColor(0.0f, 0.0f, 1.0f);
	earth.SetRotationDegree(20.0f);
	earth.SetTranslateVector(glm::vec3(0.7f, 0.0f, 0.0f));
	planets.push_back(earth);

	planet moon(0.3f);
	moon.SetColor(1.0f, 1.0f, 0.0f);
	moon.SetRotationDegree(30.0f);
	moon.SetTranslateVector(glm::vec3(0.4f, 0.0f ,0.0f));
	planets.push_back(moon);

	glfw_session.Init(640, 420, "assignment_4");
	glfw_session.Draw(planets);

	return 0;
}
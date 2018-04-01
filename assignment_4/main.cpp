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
	std::vector<Planet> planets;

	Planet sun(0.5f, 0.0f, 20.0f, 10.0f, 1.0f, 0.0f, 0.0f);
	Planet earth(0.3f, 0.5f, 20.0f, 20.0f, 0.0f, 0.0f, 1.0f);
	Planet moon(0.2f, 0.2f, 0.0f, 30.0f, 1.0f, 1.0f, 0.0f);

	earth.AddMoon(moon);
	sun.AddMoon(earth);

	planets.push_back(sun);

	glfw_session.Init(640, 420, "assignment_4");
	glfw_session.Draw(planets);

	return 0;
}
/*
Problem:
Draw a simplified clock with three needles - hour, minutes, and seconds.
The needles should rotate with different angular velocities.
(Draw one large circle and three lines moving inside the circle.)

Notes:
1. Use GL_POINTS only. Draw multiple points.
2. Use GLM library.

Hint:
GLM mat3 (You will learn easier way to make rotation matrices, later.)
*/
#include "glfw_session.h"

int main() {
	GLFWSession glfw_session;
	
	glfw_session.Init(640, 420);
	glfw_session.Draw();

	return 0;
}
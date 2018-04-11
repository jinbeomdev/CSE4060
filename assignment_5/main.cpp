/*
1. Define and draw a tetrahedron. (5 point)
2. Define and draw a cylinder.
   - draw cylinder¡¯s side only (3 point)
   - draw cylinder (2 point)
*/

#include "glfw_session.h"

int main() {
	GLFWSession glfw_session;

	glfw_session.Init(1024, 768, "assignment 5");
	glfw_session.Draw();
}
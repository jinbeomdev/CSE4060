#include "glfw_session.h"

int GLFWSession::Init(const int width_window, const int height_window, const std::string window_name) {

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode windows_ and its OpenGL context */
	windows_ = glfwCreateWindow(width_window, height_window, window_name.c_str(), NULL, NULL);

	if (!windows_)
	{
		glfwTerminate();
		return -1;
	}

	// callbacks here

	/* Make the windows_'s context current */
	glfwMakeContextCurrent(windows_);
	glClearColor(1, 1, 1, 1); // while background

	int width, height;
	glfwGetFramebufferSize(windows_, &width, &height);
	glViewport(0, 0, width, height);

	return 0;
}

void GLFWSession::Draw(std::vector<planet> &objects) {
	float revolution_1 = 0.0f;
	float revolution_2 = 0.0f;

	/* Loop until the user closes the windows_ */
	while (!glfwWindowShouldClose(windows_))
	{
		revolution_1 += 10.0f;
		revolution_2 += 20.0f;

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		//TODO: draw here
		for (int i = 0; i < objects.size(); i++) {
			objects[i].DrawPlanet();

			if (i == 0) {
				glPushMatrix();
				glRotatef(revolution_1, 0.0f, 0.0f, 1.0f);
			}

			if (i == 1) {
				glPushMatrix();
				glTranslatef(0.7f, 0.0f, 0.0f);
				glRotatef(revolution_2, 0.0f, 0.0f, 1.0f);
			}
		}

		glPopMatrix();
		glPopMatrix();

		/* Swap front and back buffers */
		glfwSwapBuffers(windows_);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();
}


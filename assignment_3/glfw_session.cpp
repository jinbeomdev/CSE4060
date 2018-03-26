#include "glfw_session.h"

int GLFWSession::Init(int width_window, int height_window) {

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode windows_ and its OpenGL context */
	windows_ = glfwCreateWindow(width_window, height_window, "Hello World", NULL, NULL);

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

void GLFWSession::Draw() {

	/* Loop until the user closes the windows_ */
	while (!glfwWindowShouldClose(windows_))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		//TODO: draw here
		glPointSize(20.0f);
		glBegin(GL_POINTS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glEnd();

		/* Swap front and back buffers */
		glfwSwapBuffers(windows_);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();
}


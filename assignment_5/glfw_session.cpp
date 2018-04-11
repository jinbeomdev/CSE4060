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

void GLFWSession::Draw() {
	/* Loop until the user closes the windows_ */
	while (!glfwWindowShouldClose(windows_))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//TODO: draw here
		glEnable(GL_DEPTH_TEST);
		Cylinder cylinder(0.5f, 0.5f);
		cylinder.Draw();


		/* Swap front and back buffers */
		glfwSwapBuffers(windows_);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();
}


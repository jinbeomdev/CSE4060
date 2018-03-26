#pragma once
#include <GLFW/glfw3.h>
#include <cstring>
#include <cstdlib>			// srand, rand
#include <thread>				// std::this_thread::sleep_for
#include <chrono>				// std::chrono::seconds
#include <iostream>

#ifndef GLFW_SESSION_H_
#define GLFW_SESSION_H_

class GLFWSession {
public:
	int Init(int width_window, int height_window);
	void Draw();

private:
	GLFWwindow *windows_ = nullptr;
};

#endif // !GLFW_SESSION_
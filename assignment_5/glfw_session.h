#pragma once
#ifndef GLFW_SESSION_H_
#define GLFW_SESSION_H_

#include <GLFW/glfw3.h>
#include <thread>				// std::this_thread::sleep_for
#include <chrono>				// std::chrono::seconds
#include <string>
#include <vector>

#include "tetrahedron.h"
#include "cylinder.h"

class GLFWSession {
public:
	int Init(const int width_window, const int height_window, const std::string window_name);
	void Draw();

private:
	GLFWwindow *windows_ = nullptr;
};

#endif // !GLFW_SESSION_H_
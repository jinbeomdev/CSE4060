#include "clock.h"
#include "simple_math.h"
#include <vec3.hpp>
#include <mat3x3.hpp>
#include <GLFW/glfw3.h>

Clock::Clock(float clock_face_radius, float hour_hand_radius,
	           float minute_hand_radius, float second_hand_radius) {
	clock_face_radius_ = clock_face_radius;
	hour_hand_radius_ = hour_hand_radius;
	minute_hand_radius_ = minute_hand_radius;
	second_hand_radius_ = second_hand_radius;
}

void Clock::DrawClock() {
	DrawClockFace();
	DrawHourHand();
	DrawMinuteHand();
	DrawSecondHand();
}

void Clock::DrawClockFace() {
	glPointSize(5.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	DrawCircle(clock_face_radius_);
}

void Clock::DrawHourHand() {
	glm::vec3 start_point = { 0.0f, 0.0f, 0.0f };
	glm::vec3 end_point = { hour_hand_radius_, 0.0f, 0.0f };

	end_point = 
		glm::transpose(SimpleMath::GetMat3RotationMatrix(end_point, -90)) * end_point;

	glm::vec3 direction_vector = end_point - start_point;
	
	glPointSize(5.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	DrawLine(direction_vector, hour_hand_radius_);
}

void Clock::DrawMinuteHand() {
	glm::vec3 start_point = { 0.0f, 0.0f, 0.0f };
	glm::vec3 end_point = { minute_hand_radius_, 0.0f, 0.0f };

	end_point =
		glm::transpose(SimpleMath::GetMat3RotationMatrix(end_point, -30)) * end_point;

	glm::vec3 direction_vector = end_point - start_point;

	glPointSize(5.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	DrawLine(direction_vector, minute_hand_radius_);
}

void Clock::DrawSecondHand() {
	glm::vec3 start_point = { 0.0f, 0.0f, 0.0f };
	glm::vec3 end_point = { second_hand_radius_, 0.0f, 0.0f };

	end_point =
		glm::transpose(SimpleMath::GetMat3RotationMatrix(end_point, -180)) * end_point;

	glm::vec3 direction_vector = end_point - start_point;

	glPointSize(5.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	DrawLine(direction_vector, second_hand_radius_);
}

void Clock::DrawLine(glm::vec3 direction_vector, float radius) {
	glBegin(GL_POINTS);
	for (float i = 0.0f; i <= radius; i += 1.0f / 256.0f) {
		glm::vec3 mid_point = 0.0f + direction_vector * i;

		glVertex3f(mid_point.x, mid_point.y, mid_point.z);
	}
	glEnd();
}

void Clock::DrawCircle(float radius) {
	glm::vec3 start_point = { radius, 0, 0 };

	glBegin(GL_POINTS);
	for (float degree = -180.0f; degree <= 180.0f; degree += 1.0f / 256.0f) {
		float radian = SimpleMath::Degree2Radian(degree);

		glm::mat3 rotation_matrix =
			glm::transpose(SimpleMath::GetMat3RotationMatrix(start_point, radian));
		glm::vec3 point = rotation_matrix * start_point;

		glVertex3f(point.x, point.y, point.z);
	}
	glEnd();
}

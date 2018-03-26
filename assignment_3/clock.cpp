#include "clock.h"
#include "simple_math.h"
#include <vec3.hpp>
#include <mat3x3.hpp>

void Clock::DrawClock() {
	glm::vec3 start_point = { clock_face_radius_, 0, 0 };

	/*
	rotation matrix = [cos, -sin
	                   sin,  cos]
	*/

	for (float degree = -180.0f; degree <= 180; degree += 1.0f) {
		float radian = SimpleMath::Degree2Radian(degree);
	}
}

void Clock::DrawClockFace() {
}

void Clock::DrawHourHand() {
}

void Clock::DrawMinuteHand() {
}

void Clock::DrawSecondHand() {
}

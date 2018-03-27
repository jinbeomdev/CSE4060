#pragma once
#ifndef CLOCK_H_
#define CLOCK_H_

#include <vec3.hpp>
#include <ctime>

class Clock {
public:
	Clock(float clock_face_radius, float hour_hand_radius,
		    float minute_hand_radius, float second_hand_radius);
	void DrawClock();

private:
	void DrawClockFace();
	void DrawHourHand();
	void DrawMinuteHand();
	void DrawSecondHand();
	void DrawLine(glm::vec3 direction_vector, float radius);
	void DrawCircle(float radius);

	std::tm* time_;
	float clock_face_radius_;
	float hour_hand_radius_;
	float minute_hand_radius_;
	float second_hand_radius_;
	float hour_hand_degree_;
	float minute_hand_degree_;
	float second_hand_degree_;
};

#endif

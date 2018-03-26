#pragma once
#ifndef CLOCK_H_
#define CLOCK_H_

class Clock {
public:
	void DrawClock();
	void DrawClockFace();
	void DrawHourHand();
	void DrawMinuteHand();
	void DrawSecondHand();

private:
	float clock_face_radius_;
	float hour_hand_radius_;
	float minute_hand_radius_;
	float second_hand_radius_;
};

#endif

#pragma once

#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

class Timer
{
private:
	system_clock::time_point _startTime, _currentTime, _lastDeltaTick;
	duration<double> _deltaTime;

public:
	Timer();
	~Timer();
	void restart();
	double getDeltaTime();
	double getElapsedTime();
	void useTimer();

protected:


};

#endif
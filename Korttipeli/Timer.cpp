/**************************************************************************************
****File:		Timer.cpp
****
****Desc:		Delay Timer for smoother cmd experience
****
****Author:		Veikka Kamppi
***************************************************************************************/


#include "Timer.h"

Timer::Timer() {
	_startTime = _currentTime = _lastDeltaTick = system_clock::now();
	_deltaTime = duration<double>(0);
}
Timer::~Timer()
{
	//cout << "Timer Destructor executed" << endl;
}

void Timer::restart()
{
	_startTime = system_clock::now();
}

double Timer::getDeltaTime()
{
	_currentTime = system_clock::now();
	_deltaTime = _currentTime - _lastDeltaTick;
	_lastDeltaTick = _currentTime;
	return _deltaTime.count();
}

/// <summary>
/// Returns elapsed time from startin point
/// </summary>
/// <returns></returns>
double Timer::getElapsedTime()
{
	_currentTime = system_clock::now();
	duration<double> elapsedTime = _currentTime - _startTime;
	return elapsedTime.count();
}

/// <summary>
/// Two second delay
/// </summary>
void Timer::Timer::useTimer()
{
	restart();
	while (getElapsedTime() < 2)
	{
		//std::cout << getElapsedTime() << std::endl;
	}
}
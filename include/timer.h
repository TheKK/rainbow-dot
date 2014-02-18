/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * timer.cpp
 *
 */

#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <SDL2/SDL.h>

class Timer
{
	public:
		Timer();

		//Timer functions
		void Start();
		void Pause();
		void Stop();
		void Unpause();
		
		//Return timer ticks
		int GetTicks();

		//Return timer status
		bool IsPaused();
		bool IsStarted();
							
	private:
		//The time when timer start
		int m_StartTicks;

		//The time when timer pause
		int m_PauseTicks;

		//Show the timer status	
		bool m_IsPuased;
		bool m_IsStarted;
};

#endif

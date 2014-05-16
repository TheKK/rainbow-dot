/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * timer.h
 *
 */

#include "timer.h"

Timer::Timer()
{
	m_StartTicks = 0;
	m_PauseTicks = 0;
	
	m_IsStarted = false;
	m_IsPuased = false;
}

Timer::~Timer()
{
}

void
Timer::Start()
{
	m_IsStarted = true;
	m_IsPuased = false;
	
	//Get the start ticks
	m_StartTicks = SDL_GetTicks();
}

void
Timer::Pause()
{
	if ((m_IsStarted == true) && (m_IsPuased == false)) {
		m_IsPuased = true;
	
		m_PauseTicks = SDL_GetTicks() - m_StartTicks;
	}
}

void
Timer::Unpause()
{
	if ((m_IsPuased == true)) {
		m_IsPuased = false;
	
		m_StartTicks = SDL_GetTicks() - m_PauseTicks;

		m_PauseTicks = 0;
	}
}
		
int
Timer::GetTicks()
{
	if (m_IsStarted == true) {
		if (m_IsPuased == false)
			return SDL_GetTicks() - m_StartTicks;
		else
			return m_PauseTicks;
	}

	return 0;
}

bool
Timer::IsPaused()	
{
	return m_IsPuased;
}

bool
Timer::IsStarted()	
{
	return m_IsStarted;
}

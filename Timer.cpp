#include "Timer.h"

//--- •Ï”éŒ¾
Frame Timer::m_fps;
Time Timer::m_deltaTime;
DWORD Timer::m_preExec;
Time Timer::m_tick = 0;
Time Timer::m_slowTime = 0;
float  Timer::m_SpeedLevel = 1;

void Timer::Init(Frame fps)
{
	SetFPS(fps);
	timeBeginPeriod(1);
	m_preExec = timeGetTime();
}

void Timer::Uninit()
{
	timeEndPeriod(1);
}

bool Timer::Update()
{
	DWORD time = timeGetTime();
	DWORD diff = time - m_preExec;

	m_tick++;

	if (diff >= 1000 / m_fps * m_SpeedLevel)
	{
		m_deltaTime = timeGetTime();
		m_preExec = time;
		if (m_tick > m_slowTime) m_SpeedLevel = 1;
		return true;
	}
	return false;
}

Time Timer::ConvertFrameToTime(Frame frame)
{
	return static_cast<float>(frame) / m_fps;
}

Frame Timer::ConvertTimeToFrame(Time time)
{
	return static_cast<Frame>(time * m_fps);
}
#include "Timer.hpp"

Timer::Timer() { start(); }

void    Timer::start()
{
    m_Start = std::chrono::high_resolution_clock::now();
}

double  Timer::elapsedSeconds()
{
    m_End = std::chrono::high_resolution_clock::now();

    auto diff = m_End - m_Start;

    auto elapsedTime = std::chrono::duration<double>(diff);

    m_Start = m_End;

    return (elapsedTime.count());
}
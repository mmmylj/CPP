#include <iostream>
#include "mytime0.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time Time::operator+(const Time & t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.hours / 60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator-(const Time & t) const
{
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + t.hours * 60;
    tot2 = minutes + hours * 60;
    diff.minutes = (tot2 - tot1) / 60;
    diff.hours = (tot2 - tot1) % 60;
    return diff;
}

Time Time::operator*(double m) const
{
    Time result;
    long tomin = (hours * 60 + minutes) * m;
    result.minutes = tomin % 60;
    result.hours = tomin / 60;
    return result; 
}

std::ostream & operator<<(std:: ostream & os, const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes.";
    return os;
}

void Time::show() const
{
    std::cout << hours << " hours, " << minutes << " minutes.";
}
#pragma once

class Date
{
public:
	unsigned int day;
	unsigned int month;
	unsigned int year;
	Date():day(1), month(1), year(2000) {}
};

class Time
{
public:
	unsigned int hour;
	unsigned int minutes;
	Time() : hour(0), minutes(0) {}
};

class Date_Time: public Date, public Time
{ 
public:
	Date_Time() : Date(), Time() {}
};
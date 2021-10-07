#include "date.h"
#include "math.h"
#include <cmath>
using namespace std;


map<int, string> iweeks{ {1, "monday"}, {2,"tuesday"}, {3, "wednesday"},{4,"thursday"},{5,"friday"},{6, "saturday"},{7,"sunday"} };


Date::Date(int year, int month, int day, int hours, int minutes, int seconds, int offset)
{
	info i{ year, month, day, hours, minutes, seconds, offset };
	set(&i);
}

void Date::set(const info* i)
{
	s = year_date(i->year)
	  + mon_days[is_leap(i->year)][i->month - 1]
	  + (i->day - 1)
	  + ((i->hours + i->offset) * 3600 + i->minutes * 60 + i->seconds) / 86400.0;
}

void Date::get(info *inf, int offset)
{
	int year = 0;
	int month = 0;
	double day = 0;
	double hours = 0;
	double minutes = 0;
	double seconds = 0;

	for (int i = 1; true && s > 0; i++)
	{
		if (i % 4 != 0)
		{
			if (s - 365 > 0)
			{
				s -= 365;
				year++;
			}
			else
				break;
		}
		else
		{
			if (s - 366 > 0)
			{
				s -= 366;
				year++;
			}
			else
				break;
		}

	}

	for (int i = 0; i < 12; i++)
	{
		if (mon_days[is_leap(year + 1900)][i] > s)
		{
			month = i;
			break;
		}
		if (i == 11) {
			month = 11;
			break;
		}

	}
	int i = 1;
	if (month == 11)
		i = 0;
	s -= mon_days[is_leap(year + 1900)][month - i] - 1;
	double time = modf(s, &day) * 86400;

	hours = whole_part(time, 3600, offset);

	minutes = whole_part(time - hours * 3600, 60);
	seconds = int(time) - hours * 3600 - minutes * 60;
	if (hours < 0)
	{
		day--;
		hours += 24;
	}
	else if (hours > 23)
	{
		day++;
		hours -= 24;
	}

	inf->year = year + 1900;
	inf->month = month;
	inf->day = day;
	inf->hours = hours;
	inf->minutes = minutes;
	inf->seconds = seconds;
	inf->offset = offset;
	
}

void Date::output(ostream& os,int offset)
{
	info i;
	i.offset = offset;
	get(&i,offset);
	os << "year: "<<i.year<<"\nmonth: "<<i.month<<"\nday: "<<i.day << "\nhours: " << i.hours << "\nminutes: "<<i.minutes<<"\nseonds: "<<i.seconds <<"\noffset: "<< i.offset<<"\nweek in year: "<<week_num(i.year,i.month,i.day) <<"\nweek in month: "<< week_num(i.year, i.month, i.day) - week_num(i.year, i.month, 1) + 1;

}



double to_double(int year, int month, int day, int hours, int minutes, int seconds, int offset)
{
	return year_date(year) + mon_days[is_leap(year)][month - 1] + day + ((hours + offset) * 3600 + minutes * 60 + seconds) / 86400.0;
}

string Date::w_day()
{
	return iweeks[int(s) % 7];
}
int Date::week_num(int year, int month, int day)
{
	return (7 + mon_days[is_leap(year)][month - 1] + (day - 1) - (int(to_double(year, month, day - 1, 0, 0, 0, 0)) % 7)) / 7;
}


int whole_part(double s,int seconds, double offset )
{
	int res = 0;
	for (int i = 0; true && s > 0; i++)
	{
		if (s - seconds > 0)
		{
			s -= seconds;
			res++;
		}
		else
			break;
	}
	return res - offset;
}

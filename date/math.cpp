#include "math.h"
#include "date.h"
#include <map>
using namespace std;
int is_leap(long y)
{
    return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) ? 1 : 0;
}

long year_date(long y)
{
    return ((y - 1900) * 365
        + ((y - 1) / 4 - 1900 / 4)
        - ((y - 1) / 100 - 1900 / 100)
        + ((y - 1) / 400 - 1900 / 400));
}

double sub(double first, double second)
{
	to_date(abs(first - second), 0);
    return abs(first - second);
}

double sum(double first, double second)
{
	to_date(abs(first + second), 0);
    return abs(first + second);
}

void to_date(double s,int offset)
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

	cout << "year: " << year << "\nmonth: " << month << "\nday: " << day << "\nhours: " << hours << "\nminutes: " << minutes << "\nseonds: " << seconds << "\noffset: " << offset << '\n';
}
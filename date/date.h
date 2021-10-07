#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;



class Date
{
	double s;

public:
	struct info
	{
		int year;
		int month;
		int day;
		int hours;
		int minutes;
		int seconds;
		int offset;
	};

	Date() : s(0.0) { }
	Date(const Date&) = default;

	Date(int year, int month, int day, int hours, int minutes, int seconds, int offset);

	void set(const info *i);
	void get(info* inf,int offset);

	void output(ostream& os,int offset);
	string w_day();
	int week_num(int year, int month, int day);
	
	double get_d() { return s; }
};

int whole_part(double s, int seconds, double offset = 0);
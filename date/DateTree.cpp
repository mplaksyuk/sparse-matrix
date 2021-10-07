#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include "BinarySearchTree.h"
#include "date.h"
#include "math.h"


int main() {
	int id_f, id_s;
	int id, offset;
	vector<Date> date;
	vector<double> buffer;
	
	while (true) {
		cout << "1.add\n"
			<< "2.output\n"
			<< "3.week day\n"
			<< "4.sub\n"
			<< "5.sum\n"
			<< "6.add from buffer\n";
		int ans;
		cin >> ans;
		switch (ans)
		{
		case 1:
			int year;
			cout << "year: ";
			cin >> year;
			while (year < 0)
			{
				cout << "try again: ";
				cin >> year;
			}
			int month;
			cout << "month: ";
			cin >> month;
			while (month < 1 || month > 12)
			{
				cout << "try again: ";
				cin >> month;
			}
			int day;
			cout << "day: ";
			cin >> day;

			while (day < 0 || day > 30 || day > mon_days[is_leap(year)][month - 1] - mon_days[is_leap(year)][month - 2])
			{
				cout << "try again: ";
				cin >> day;
			}
			int hours;
			cout << "hours: ";
			cin >> hours;
			while (hours < 0 || hours > 23)
			{
				cout << "try again: ";
				cin >> hours;
			}
			int minutes;
			cout << "minutes: ";
			cin >> minutes;
			while (minutes < 0 || minutes > 59)
			{
				cout << "try again: ";
				cin >> minutes;
			}
			int seconds;
			cout << "seconds: ";
			cin >> seconds;
			while (seconds < 0 || seconds > 59)
			{
				cout << "try again: ";
				cin >> seconds;
			}
			int offset;
			cout << "offset: ";
			cin >> offset;
			while (offset < -12 || offset > 12)
			{
				cout << "try again: ";
				cin >> offset;
			}

			date.push_back({ year, month, day, hours, minutes, seconds, offset });
			cout << "index: " << date.size()<<'\n';
			break;
		case 2:

			cout << "id: ";
			cin >> id;
			while (id > date.size())
			{
				cout << "try again: ";
				cin >> id;
			}
			cout << "offset: ";
			cin >> offset;
			while (offset < -12 || offset > 12)
			{
				cout << "try again: ";
				cin >> offset;
			}
			date[id].output(cout, offset);
			break;
		case 3:
			int id;
			cout << "id: ";
			cin >> id;
			while (id > date.size())
			{
				cout << "try again: ";
				cin >> id;
			}

			date[id].w_day();
			break;
		case 4:


			cout << "id: ";
			cin >> id_f;
			while (id_f > date.size())
			{
				cout << "try again: ";
				cin >> id_f;
			}
			cout << "id: ";
			cin >> id_s;
			while (id_s > date.size())
			{
				cout << "try again: ";
				cin >> id_s;
			}

			buffer.push_back(sub(date[id_f].get_d(), date[id_s].get_d()));
			break;
		case 5:


			cout << "id: ";
			cin >> id_f;
			while (id_f > date.size())
			{
				cout << "try again: ";
				cin >> id_f;
			}
			cout << "id: ";
			cin >> id_s;
			while (id_s > date.size())
			{
				cout << "try again: ";
				cin >> id_s;
			}

			sum(date[id_f].get_d(), date[id_s].get_d());
			break;
		case 6:


			cout << "id: ";
			cin >> id_f;
			while (id_f > date.size())
			{
				cout << "try again: ";
				cin >> id_f;
			}
			for (int i = 0; i < buffer.size(); i++)
			{
				cout << i << ".\n";
				to_date(buffer[i], 0);
			}
			cout << "id: ";
			cin >> id_s;
			while (id_s > buffer.size())
			{
				cout << "try again: ";
				cin >> id_s;
			}

			sum(date[id_f].get_d(), buffer[id_s]);

			break;
		}
	}
}
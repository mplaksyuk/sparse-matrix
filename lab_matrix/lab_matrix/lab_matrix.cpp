#include <iostream>
#include <map>
#include "map_matrix.h"
#include "map_math.h"

using namespace std;

int main()
{

	cout << "1.map:\n";
	int ans;
	cin >> ans;
	switch (ans) {
	case 1:
		class matrix matrix1;
		class matrix matrix2;
		class matrix matrix3;
		class matrix buf;
		map_create_matrix(&matrix1);


		while (true)
		{
			int line, column;

			cout << "1.insert element by index.\n"
				<< "2.show matrix.\n"
				<< "3.addition matrix.\n"
				<< "4.subtraction matrix.\n"
				<< "5.multiply matrix.\n"
				<< "6.create or update matrix.\n"
				<< "7.transpose.\n"
				<< "8.multiply on vector.\n"
				<< "9.find\n";

			cin >> ans;
			switch (ans) {
			case 1:

				cout << "i and j: ";
				cin >> line;
				cin >> column;
				cout << "how matrix?";
				cin >> ans;
				switch (ans) {
				case 1:
					cout << map_insert_by_index(&matrix1, line, column) << '\n';
					break;
				case 2:
					if (!map_ccount(&matrix2))
						cout << "matrix empty.\n";
					else
						cout << map_insert_by_index(&matrix2, line, column) << '\n';
					break;
				case 3:
					if (!map_ccount(&matrix3))
						cout << "matrix empty.\n";
					else
						cout << map_insert_by_index(&matrix3, line, column) << '\n';
					break;
				}
				break;
			case 2:
				cout << "how matrix show?";
				cin >> ans;
				switch (ans) {
				case 1:
					map_show_matrix(&matrix1);
					break;
				case 2:
					if (!map_ccount(&matrix2))
						cout << "matrix empty.\n";
					else
						 map_show_matrix(&matrix2);
					break;
				case 3:
					if (!map_ccount(&matrix3))
						cout << "matrix empty.\n";
					else
						map_show_matrix(&matrix3);
					break;
				}
				break;
			case 3:
				cout << "1. F_matrix + S_matrix.\n";
				cout << "2. S_matrix + F_matrix.\n";
				cin >> ans;
				switch (ans) {
				case 1:
					if (!map_ccount(&matrix2))
						cout << "matrix2 empty.\n";
					else
						matrix3 = map_sum(&matrix1, &matrix2);
					break;
				case 2:
					if (!map_ccount(&matrix2))
						cout << "matrix2 empty.\n";
					else
						matrix3 = map_sum(&matrix2, &matrix1);
					break;
				}
				cout << "Resurl in matrix3\n";
				break;
			case 4:
				cout << "1. F_matrix - S_matrix.\n";
				cout << "2. S_matrix - F_matrix.\n";
				cin >> ans;
				switch (ans) {
				case 1:
					if (!map_ccount(&matrix2))
						cout << "matrix2 empty.\n";
					else
						matrix3 = map_sub(&matrix1, &matrix2);
					break;
				case 2:
					if (!map_ccount(&matrix2))
						cout << "matrix2 empty.\n";
					else
						matrix3 = map_sub(&matrix2, &matrix1);
					break;
				}
				cout << "Resurl in matrix3\n";
				break;
			case 5:

				cout << "1. F_matrix * S_matrix.\n";
				cout << "2. S_matrix * F_matrix.\n";

				cin >> ans;
				switch (ans) {
				case 1:
					if (!map_ccount(&matrix2))
						cout << "matrix2 empty.\n";
					else
						if (map_lcount(&matrix2) == map_ccount(&matrix1))
							matrix3 = map_multiply(&matrix1, &matrix2);
						else
							cout << "The number of columns in the first matrix must be equal to the number of rows in the second.\n";
					break;
				case 2:
					if (!map_ccount(&matrix2))
						cout << "matrix2 empty.\n";
					else
						if (map_ccount(&matrix2) == map_lcount(&matrix1))
							matrix3 = map_multiply(&matrix2, &matrix1);
						else
							cout << "The number of columns in the first matrix must be equal to the number of rows in the second.\n";
					break;
				}
				break;
			case 6:

				cout << "1.upgrade F_matrix\n";
				cout << "2.upgrade S_matrix.\n";

				cin >> ans;
				switch (ans) {
				case 1:
					cout << "update matrix1:\n";
					map_create_matrix(&matrix1);
					break;
				case 2:
					if (!map_ccount(&matrix2)) {
						cout << "create matrix2:\n";
						map_create_matrix(&matrix2);
					}
					else {
						cout << "update matrix2:\n";
						map_create_matrix(&matrix2);
					}
				}
				break;
				break;
			case 7:
				cout << "1.Transpose F_matrix\n";
				cout << "2.Transpose S_matrix.\n";
				cout << "3.Transpose S_matrix.\n";

				cin >> ans;
				switch (ans) {
				case 1:
					if (map_ccount(&matrix1)) {

						matrix1 = map_transpose(&matrix1);
					}
					break;
				case 2:
					if (map_ccount(&matrix2)) {

						matrix2 = map_transpose(&matrix2);
					}
					break;
				case 3:
					if (map_ccount(&matrix3)) {

						matrix3 = map_transpose(&matrix3);
					}
					break;
				}
				break;
			case 8:

				cout << "1. F_matrix * vector.\n"
					<< "2. S_matrix * vector.\n"
					<< "3. T_matrix * vector.\n";

				cin >> ans;
				switch (ans) {
				case 1:
					buf = map_create_vector(&matrix1);
					matrix1 = map_multiply(&matrix1, &buf);
					break;
				case 2:
					if (!map_ccount(&matrix2))
						cout << "matrix2 empty.\n";
					else
						buf = map_create_vector(&matrix2);
					matrix2 = map_multiply(&matrix2, &buf);
					break;
				case 3:
					if (!map_ccount(&matrix3))
						cout << "matrix2 empty.\n";
					else
						buf = map_create_vector(&matrix3);
					matrix3 = map_multiply(&matrix3, &buf);
					break;
				}
				break;
			case 9:
				cout << "1. F_matrix.\n"
					<< "2.S_mastrix.\n"
					<< "3.T_matrix.\n";
				cin >> ans;
				switch (ans) {
				case 1:
					cout << "1.search by index.\n"
						<< "2.search by digit.\n"
						<< "3.search by number.\n";
					cin >> ans;
					switch (ans) {
					case 1:
						cout << "i and j: ";
						cin >> line;
						cin >> column;
						cout << map_insert_by_index(&matrix1, line, column);
						break;
					case 2:
						cout << "digit:";
						int digit;
						cin >> digit;
						map_insert_by_digit(&matrix1, digit);
						break;
					case 3:
						cout << "value:";
						int value;
						cin >> value;
						map_insert_by_value(&matrix1, value);
						break;
					}
					break;
				case 2:
					cout << "1.search by index.\n"
						<< "2.search by digit.\n"
						<< "3.search by number.\n";
					cin >> ans;
					switch (ans) {
					case 1:
						cout << "i and j: ";
						cin >> line;
						cin >> column;
						cout << map_insert_by_index(&matrix2, line, column);
						break;
					case 2:
						cout << "digit:";
						int digit;
						cin >> digit;
						map_insert_by_digit(&matrix2, digit);
						break;
					case 3:
						cout << "value:";
						int value;
						cin >> value;
						map_insert_by_value(&matrix2, value);
						break;
					}
					break;
				case 3:
					cout << "1.search by index.\n"
						<< "2.search by digit.\n"
						<< "3.search by number.\n";
					cin >> ans;
					switch (ans) {
					case 1:
						cout << "i and j: ";
						cin >> line;
						cin >> column;
						cout << map_insert_by_index(&matrix3, line, column);
						break;
					case 2:
						cout << "digit:";
						int digit;
						cin >> digit;
						map_insert_by_digit(&matrix3, digit);
						break;
					case 3:
						cout << "value:";
						int value;
						cin >> value;
						map_insert_by_value(&matrix3, value);
						break;
					}
					break;
				}
				break;
				}
			}
		}
	}
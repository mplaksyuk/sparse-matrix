#include "map_math.h"
#include "map_matrix.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

matrix map_sum(class matrix* matrix1, class matrix* matrix2)
{
	class matrix matrix3;
	if (map_lcount(matrix1) == map_lcount(matrix2) && map_ccount(matrix1) == map_ccount(matrix2))
	{
		matrix3.line = map_lcount(matrix1);
		matrix3.column = map_ccount(matrix1);
		for (int i = 0; i < map_lcount(matrix1); i++) {
			for (int j = 0; j < map_ccount(matrix1); j++) {
				map_update_by_index(&matrix3, i, j, map_insert_by_index(matrix1, i, j) + map_insert_by_index(matrix2, i, j));
			}
		}
		return matrix3;
	}
	else{
		cout << "Matrix sizes must be the same.\n";
		return matrix3;
	}
}

matrix map_sub(class matrix* matrix1, class matrix* matrix2)
{
	class matrix matrix3;
	
	if (map_lcount(matrix1) == map_lcount(matrix2) && map_ccount(matrix1) == map_ccount(matrix2))
	{
		matrix3.line = map_lcount(matrix1);
		matrix3.column = map_ccount(matrix1);

		for (int i = 0; i < map_lcount(matrix1); i++) {
			for (int j = 0; j < map_ccount(matrix1); j++) {
				map_update_by_index(&matrix3, i, j, map_insert_by_index(matrix1, i, j) - map_insert_by_index(matrix2, i, j));
			}
		}
		return matrix3;
	}
	else {
		cout << "Matrix sizes must be the same.\n";
		return matrix3;
	}
}

matrix map_multiply(class matrix* matrix1, class matrix* matrix2)
{
	class matrix matrix3;
	vector<int> vector;
	

	int minimal = min(min(map_lcount(matrix1), map_ccount(matrix1)), min(map_lcount(matrix2), map_ccount(matrix2)));
	int maximal = max(max(map_lcount(matrix1), map_ccount(matrix1)), max(map_lcount(matrix2), map_ccount(matrix2)));
	if (map_lcount(matrix2) == map_ccount(matrix1))
	{
		matrix3.line = maximal;
		matrix3.column = minimal;

		for (int line = 0; line < maximal; line++) {
			for (int column = 0; column < minimal; column++) {
				for (int k = 0; k < maximal; k++) {
					map_update_by_index(&matrix3, line, column, map_insert_by_index(matrix1, line, k) * map_insert_by_index(matrix2, k, column));
				}
			}
		}
		return matrix3;
	}
	else {

		cout << "The number of columns in the first matrix must be equal to the number of rows in the second.\n";
		return matrix3;
	}
}

int map_show_matrix(class matrix* matrix) {
	for (int i = 0; i < map_lcount(matrix); i++) {
		for (int j = 0; j < map_ccount(matrix); j++) {
			cout << map_insert_by_index(matrix, i, j) << '\t';
		}
		cout << '\n';
	}
	return 0;
}
matrix map_transpose(class matrix* matrix) {
	class matrix matrix3;
	matrix3.line = map_ccount(matrix);
	matrix3.column = map_lcount(matrix);
	for (int i = 0; i < map_lcount(matrix); i++) {
		for (int j = 0; j < map_ccount(matrix); j++) {
			map_update_by_index(&matrix3, i, j, map_insert_by_index(matrix, j, i));
		}
	}
	return matrix3;
}
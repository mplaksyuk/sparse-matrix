#include "map_math.h"
#include "map_matrix.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

matrix map_sum(class matrix* matrix1, class matrix* matrix2)
{
	class matrix matrix3;
	if (matrix1->map_lcount() == matrix2->map_lcount() && matrix1->map_ccount() == matrix2->map_ccount())
	{
		matrix3.map_set_line(matrix1->map_lcount());
		matrix3.map_set_column(matrix1->map_ccount());
		for (int i = 0; i < matrix1->map_lcount(); i++) {
			for (int j = 0; j < matrix1->map_ccount(); j++) {
				matrix3.map_update_by_index( i, j, matrix1->map_insert_by_index(i, j) + matrix2->map_insert_by_index(i, j));
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
	
	if (matrix1->map_lcount() == matrix2->map_lcount() && matrix1->map_ccount() == matrix2->map_ccount())
	{
		matrix3.map_set_line(matrix1->map_lcount());
		matrix3.map_set_column(matrix1->map_ccount());

		for (int i = 0; i < matrix1->map_lcount(); i++) {
			for (int j = 0; j < matrix1->map_ccount(); j++) {
				matrix3.map_update_by_index(i, j, matrix1->map_insert_by_index(i, j) - matrix2->map_insert_by_index(i, j));
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
	

	int minimal = min(min(matrix1->map_lcount(), matrix1->map_ccount()), min(matrix2->map_lcount(), matrix2->map_ccount()));
	int maximal = max(max(matrix1->map_lcount(), matrix1->map_ccount()), max(matrix2->map_lcount(), matrix2->map_ccount()));
	if (matrix2->map_lcount() == matrix1->map_ccount())
	{
		matrix3.map_set_line(maximal);
		matrix3.map_set_column(minimal);

		for (int line = 0; line < maximal; line++) {
			for (int column = 0; column < minimal; column++) {
				for (int k = 0; k < maximal; k++) {
					matrix3.map_update_by_index(line, column, matrix1->map_insert_by_index(line, k) * matrix1->map_insert_by_index(k, column));
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
	for (int i = 0; i < matrix->map_lcount(); i++) {
		for (int j = 0; j < matrix->map_ccount(); j++) {
			cout << matrix->map_insert_by_index( i, j) << '\t';
		}
		cout << '\n';
	}
	return 0;
}
matrix map_transpose(class matrix* matrix) {
	class matrix matrix3;
	matrix3.map_set_line(matrix->map_lcount());
	matrix3.map_set_column(matrix->map_ccount());
	for (int i = 0; i < matrix->map_lcount(); i++) {
		for (int j = 0; j < matrix->map_ccount(); j++) {
			matrix3.map_update_by_index(i, j, matrix->map_insert_by_index(j, i));
		}
	}
	return matrix3;
}
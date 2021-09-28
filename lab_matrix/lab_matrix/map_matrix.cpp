#include "map_matrix.h"
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <stdio.h>

using namespace std;

int map_create_matrix(class matrix* matrix)
{
	cout << "line: ";
	cin >> matrix->line;

	cout << "column: ";
	cin >> matrix->column;


	for (int i = 0; i < matrix->line; i++) {
		for (int j = 0; j < matrix->column; j++) {
			printf("matrix[%d][%d]:", i, j);
			int buf;
			cin >> buf;
			if(buf != 0)
				matrix->map[make_pair(i,j)] = buf;
		}
	}
	return 0;
}

int map_lcount(class matrix* matrix)
{
	return matrix->line;
}

int map_ccount(class matrix* matrix)
{
	return matrix->column;
}

int map_insert_by_index(class matrix* matrix, int line, int column)
{
	if(matrix->map.find(make_pair(line, column)) != matrix->map.end())
		return matrix->map.find(make_pair(line,column))->second;
	return 0;
}

vector<int> map_insert_column(class matrix* matrix, int num_column)
{
	vector<int> vector;
	for (int i = 0; i < matrix->line; i ++)
		vector.push_back(map_insert_by_index(matrix, i, num_column));
	return vector;
}

vector<int> map_insert_line(class matrix* matrix, int num_line)
{
	vector<int> vector;
	for (int i = 0; i < matrix->column; i++)
		vector.push_back(map_insert_by_index(matrix, num_line, i));
	return vector;
}

int scalar_product(vector<int> vector1, vector<int> vector2)
{
	int result = 0;

	for (int i = 0; i < vector1.size(); i++)
		result += vector1[i] * vector2[i];
	
	return result;
}

int map_update_by_index(class matrix* matrix, int line, int column, int value)
{
	matrix->map[make_pair(line, column)] = map_insert_by_index(matrix,line,column) + value;
	return 0;
}

matrix map_create_vector(class matrix *matrix)
{
	class matrix matrix2;
	matrix2.line = matrix->column;
	matrix2.column = 1;

	for (int i = 0; i < matrix2.line; i++) {
		for (int j = 0; j < matrix2.column; j++) {
			printf("vector[%d][%d]:", i, j);
			int buf;
			cin >> buf;
			if (buf != 0)
				matrix2.map[make_pair(i, j)] = buf;
		}
	}
	return matrix2;
}

int map_insert_by_digit(class matrix* matrix, int digit)
{
	int buf;
	for (int i = 0; i < matrix->line; i++) {
		for (int j = 0; j < matrix->column; j++) {
			buf = map_insert_by_index(matrix, i, j);
			while (buf != 0) {
				if (buf % 10 == digit) {
					cout << "matrix[" << i << "][" << j << "] : " << map_insert_by_index(matrix, i, j) << '\n';
					return 1;
				}
				else {
					buf /= 10;
				}
			}
		}
	}
	return 0;
}
int map_insert_by_value(class matrix* matrix, int value) {
	for (int i = 0; i < matrix->line; i++) {
		for (int j = 0; j < matrix->column; j++) {
			if (map_insert_by_index(matrix, i, j) == value) {
				cout << "matrix[" << i << "][" << j << "] : " << map_insert_by_index(matrix, i, j) << '\n';
				return 1;
			}
		}	
	}
	return 0;
}
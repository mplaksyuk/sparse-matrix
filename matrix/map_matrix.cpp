#include "map_matrix.h"
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <stdio.h>

using namespace std;

int matrix:: map_create_matrix()
{
	cout << "line: ";
	cin >> this->line;

	cout << "column: ";
	cin >> this->column;


	for (int i = 0; i < this->line; i++) {
		for (int j = 0; j < this->column; j++) {
			printf("matrix[%d][%d]:", i, j);
			int buf;
			cin >> buf;
			if(buf != 0)
				this->map[make_pair(i,j)] = buf;
		}
	}
	return 0;
}

matrix::matrix()
{
}

matrix::~matrix()
{
}
void matrix::map_set_line(int value)
{
	this->line = value;
}
void matrix::map_set_column(int value)
{
	this->column = value;
}
int matrix::map_lcount()
{
	return this->line;
}

int matrix:: map_ccount()
{
	return this->column;
}

int matrix:: map_insert_by_index(int line, int column)
{
	if(this->map.find(make_pair(line, column)) != this->map.end())
		return this->map.find(make_pair(line,column))->second;
	return 0;
}

vector<int> matrix:: map_insert_column(int num_column)
{
	vector<int> vector;
	for (int i = 0; i < this->map_lcount(); i ++)
		vector.push_back(this->map_insert_by_index(i, num_column));
	return vector;
}

vector<int> matrix:: map_insert_line(int num_line)
{
	vector<int> vector;
	for (int i = 0; i < this->map_ccount(); i++)
		vector.push_back(this->map_insert_by_index(num_line, i));
	return vector;
}

int matrix:: scalar_product(vector<int> vector1, vector<int> vector2)
{
	int result = 0;

	for (int i = 0; i < vector1.size(); i++)
		result += vector1[i] * vector2[i];
	
	return result;
}

int matrix:: map_update_by_index(int line, int column, int value)
{
	this->map[make_pair(line, column)] = this->map_insert_by_index(line,column) + value;
	return 0;
}

matrix matrix::map_create_vector()
{
	class matrix matrix2;
	matrix2.line = this->column;
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

int matrix::map_insert_by_digit(int digit)
{
	int buf;
	for (int i = 0; i < this->line; i++) {
		for (int j = 0; j < this->column; j++) {
			buf = this->map_insert_by_index( i, j);
			while (buf != 0) {
				if (buf % 10 == digit) {
					cout << "matrix[" << i << "][" << j << "] : " << this->map_insert_by_index( i, j) << '\n';
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
int matrix::map_insert_by_value(int value) {
	for (int i = 0; i < this->line; i++) {
		for (int j = 0; j < this->column; j++) {
			if (this->map_insert_by_index(i, j) == value) {
				cout << "matrix[" << i << "][" << j << "] : " << this->map_insert_by_index(i, j) << '\n';
				return 1;
			}
		}	
	}
	return 0;
}
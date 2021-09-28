#pragma once
#include <map>
#include <vector>
#include <utility>
using namespace std;

class matrix {
public:
	map<pair<int, int>, double> map;

	int line, column;
};

int map_lcount(class matrix* matrix);
int map_ccount(class matrix* matrix);
int map_create_matrix(class matrix* matrix);
int map_insert_by_index(class matrix* matrix, int i, int j);
vector<int> map_insert_column(class matrix* matrix, int num_column);
vector<int> map_insert_line(class matrix* matrix, int num_line);
int scalar_product(vector<int> vector1, vector<int> vector2);
int map_update_by_index(class matrix* matrix, int i, int j, int value);
matrix map_create_vector(class matrix* matrix);
int map_insert_by_digit(class matrix* matrix, int digit);
int map_insert_by_value(class matrix* matrix, int value);
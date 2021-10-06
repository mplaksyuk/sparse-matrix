#pragma once
#include <map>
#include <vector>
#include <utility>
using namespace std;

class matrix {

public:
	matrix();
	~matrix();
	void map_set_line(int value);
	void map_set_column(int value);
	int map_lcount();
	int map_ccount();
	int map_create_matrix();
	int map_insert_by_index( int i, int j);
	vector<int> map_insert_column(int num_column);
	vector<int> map_insert_line(int num_line);
	int scalar_product(vector<int> vector1, vector<int> vector2);
	int map_update_by_index( int i, int j, int value);
	matrix map_create_vector();
	int map_insert_by_digit(int digit);
	int map_insert_by_value(int value);
private:
	map<pair<int, int>, double> map;

	int line, column;
};



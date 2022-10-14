#pragma once
#include<tuple>
#include<vector>
#include<map>

using namespace std;

struct coord
{
	coord() {

	}
	coord(int r, int c) {
		row = r;
		col = c;
	}
	int row = 0;
	int col = 0;

	coord operator+(const coord& other)
	{
		coord result;
		result.row = this->row + other.row;
		result.col = this->col + other.col;
		return result;
	}
};

typedef vector<coord> movelisttype;
typedef map<char, vector<char>> movemaptype;
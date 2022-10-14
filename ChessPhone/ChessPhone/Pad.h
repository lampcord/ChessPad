#pragma once
#include <string>
#include <map>
#include "Types.h"

class Pad
{
private:
	coord dimensions;
	string tokens;
	map<char, coord> symboltocoordmap;
	unsigned int CoordToNdx(coord c);
	coord NdxToCoord(unsigned int ndx);
	char NdxToSymbol(unsigned int ndx);
public:

	Pad(coord dimensions, string tokens);
	~Pad() {};

	coord SymbolToCoord(char symbol);
	char CoordToSymbol(coord c);

	coord GetDimensions() { return dimensions; }
	int GetLargestMove() {
		return dimensions.col > dimensions.row ? dimensions.col - 1 : dimensions.row - 1;
	}
	bool isValidCoord(coord c);
	movelisttype GetAllLocations();

	void dump();
};


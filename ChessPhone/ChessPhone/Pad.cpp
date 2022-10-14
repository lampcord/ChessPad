#include "Pad.h"
#include <iostream>

Pad::Pad(coord dimensions, string tokens) {
	this->dimensions = dimensions;
	this->tokens = tokens;

	for (auto r = 0; r < dimensions.row; r++)
	{
		for (auto c = 0; c < dimensions.col; c++)
		{
			coord cd(r, c);
			symboltocoordmap[CoordToSymbol(cd)] = cd;
		}
	}
}

unsigned int Pad::CoordToNdx(coord c)
{
	return c.row * dimensions.col + c.col;
}

coord Pad::NdxToCoord(unsigned int ndx)
{
	return coord(ndx / dimensions.col, ndx % dimensions.col);
}

coord Pad::SymbolToCoord(char symbol)
{
	if (symboltocoordmap.count(symbol) > 0) return symboltocoordmap[symbol];
	return coord(-1, -1);
}

char Pad::CoordToSymbol(coord c)
{
	return NdxToSymbol(CoordToNdx(c));
}

char Pad::NdxToSymbol(unsigned int ndx)
{
	char symbol = 0;

	if (ndx >= 0 && ndx < (int)tokens.size()) {
		symbol = tokens[ndx];
	}

	return symbol;
}

bool Pad::isValidCoord(coord c)
{
	return (c.row >= 0 && c.row < dimensions.row && c.col >= 0 && c.col < dimensions.col);
}

movelisttype Pad::GetAllLocations()
{
	movelisttype locations;

	for (auto r = 0; r < dimensions.row; r++)
	{
		for (auto c = 0; c < dimensions.col; c++)
		{
			locations.push_back(coord(r, c));
		}
	}

	return locations;
}

void Pad::dump()
{
	for (auto r = 0; r < dimensions.row; r++)
	{
		for (auto c = 0; c < dimensions.col; c++)
		{
			cout << CoordToSymbol(coord(r, c)) << " ";
		}
		cout << endl;
	}
}

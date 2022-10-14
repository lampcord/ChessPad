#pragma once
#include "Types.h"
#include <string>

class Piece
{
public:
	Piece() {};
	~Piece() {};

	virtual string GetName() = 0;
	virtual movelisttype GetMoveList(unsigned int maxDistance) = 0;
	virtual bool isValidStartingPosition(coord c) {
		return true;
	};
};

class Queen : public Piece
{
public:
	virtual string GetName() { return "Queen"; }
	virtual movelisttype GetMoveList(unsigned int maxDistance);

}; 
class Rook : public Piece
{
public:
	virtual string GetName() { return "Rook"; }
	virtual movelisttype GetMoveList(unsigned int maxDistance);

};
class Bishop : public Piece
{
public:
	virtual string GetName() { return "Bishop"; }
	virtual movelisttype GetMoveList(unsigned int maxDistance);

};
class Knight : public Piece
{
public:
	virtual string GetName() { return "Knight"; }
	virtual movelisttype GetMoveList(unsigned int maxDistance);

};
class King : public Piece
{
public:
	virtual string GetName() { return "King"; }
	virtual movelisttype GetMoveList(unsigned int maxDistance);

};
class Pawn : public Piece
{
public:
	virtual string GetName() { return "Pawn"; }
	virtual movelisttype GetMoveList(unsigned int maxDistance);

};

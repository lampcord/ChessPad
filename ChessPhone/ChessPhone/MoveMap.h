#pragma once
#include <vector>
#include "Piece.h"
#include "Pad.h"
#include "Validator.h"

namespace MoveMapper
{
	void Initialize();
	movemaptype GetMoveMapping(Piece &piece, Pad &pad, Validator validator);
	int GetAllLegalMoves(Piece& piece, Pad& pad, Validator validator);
};


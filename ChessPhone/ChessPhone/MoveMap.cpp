#include "MoveMap.h"
#include <queue>

struct counter {
	int count = 0;
	char lastchar = '\0';
};
vector<counter> fast_queue;
long fast_queue_count = 0;

namespace MoveMapper
{
	void Initialize()
	{
		fast_queue.reserve(1000);
	}

	movemaptype GetMoveMapping(Piece& piece, Pad& pad, Validator validator)
	{
		movemaptype movemap;

		movelisttype locations = pad.GetAllLocations();
		movelisttype moves = piece.GetMoveList(pad.GetLargestMove());

		for (auto location : locations)
		{
			if (!validator.IsValidNonFirstDigit(pad.CoordToSymbol(location))) continue;

			for (auto move : moves)
			{
				auto target = location + move;
				if (!validator.IsValidNonFirstDigit(pad.CoordToSymbol(target))) continue;
				if (pad.isValidCoord(target)) movemap[pad.CoordToSymbol(location)].push_back(pad.CoordToSymbol(target));
			}
		}

		return movemap;
	}

	int GetAllLegalMoves(Piece& piece, Pad& pad, Validator validator)
	{
		int max_queue_size = 0;
		int legalmoves = 0;
		fast_queue_count = 0;

		auto mm = GetMoveMapping(piece, pad, validator);

		for (auto mtuple : mm)
		{
			if (!validator.IsValidFirstDigit(mtuple.first)) continue;
			if (piece.isValidStartingPosition(pad.SymbolToCoord(mtuple.first)))
			{
				fast_queue_count++;
				fast_queue[fast_queue_count - 1].count = 1;
				fast_queue[fast_queue_count - 1].lastchar = mtuple.first;
			}
		}

		while (fast_queue_count > 0)
		{
			auto candidate = fast_queue[fast_queue_count - 1];
			fast_queue_count--;

			if (validator.IsValidLength(candidate.count))
			{
				legalmoves++;
				continue;
			}

			auto lastchar = candidate.lastchar;

			if (mm.count(lastchar) == 0) continue;

			for (auto dest : mm[lastchar])
			{
				auto newcandidate = candidate;
				newcandidate.count++;
				newcandidate.lastchar = dest;
				fast_queue_count++;
				fast_queue[fast_queue_count - 1].count = newcandidate.count;
				fast_queue[fast_queue_count - 1].lastchar = newcandidate.lastchar;
			}
		}

		return legalmoves;
	}

}

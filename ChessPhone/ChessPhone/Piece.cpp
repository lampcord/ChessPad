#include "Piece.h"

movelisttype Rook::GetMoveList(unsigned int maxDistance)
{
    movelisttype moves;

    for (auto x = 1; x <= (int)maxDistance; x++)
    {
        moves.push_back({ x, 0 });
        moves.push_back({ -x, 0 });
        moves.push_back({ 0, x });
        moves.push_back({ 0, -x });
    }

    return moves;
}

movelisttype Queen::GetMoveList(unsigned int maxDistance)
{
    movelisttype moves;

    for (auto x = 1; x <= (int)maxDistance; x++)
    {
        moves.push_back({ x, 0 });
        moves.push_back({ -x, 0 });
        moves.push_back({ 0, x });
        moves.push_back({ 0, -x });
        moves.push_back({ -x, -x });
        moves.push_back({ x, -x });
        moves.push_back({ -x, x });
        moves.push_back({ x, x });
    }

    return moves;
}

movelisttype Bishop::GetMoveList(unsigned int maxDistance)
{
    movelisttype moves;

    for (auto x = 1; x <= (int)maxDistance; x++)
    {
        moves.push_back({ -x, -x });
        moves.push_back({ x, -x });
        moves.push_back({ -x, x });
        moves.push_back({ x, x });
    }

    return moves;
}

movelisttype Knight::GetMoveList(unsigned int maxDistance)
{
    movelisttype moves;

    for (auto x = 1; x <= (int)maxDistance; x++)
    {
        moves.push_back({ -x, -2 * x });
        moves.push_back({ x, -2 * x });
        moves.push_back({ -x, 2 * x });
        moves.push_back({ x, 2 * x });
        moves.push_back({ -2 * x, -x });
        moves.push_back({ 2 * x, -x });
        moves.push_back({ -2 * x, x });
        moves.push_back({ 2 * x, x });
    }

    return moves;
}

movelisttype King::GetMoveList(unsigned int maxDistance)
{
    movelisttype moves;

    moves.push_back({ 1, 0 });
    moves.push_back({ -1, 0 });
    moves.push_back({ 0, 1 });
    moves.push_back({ 0, -1 });
    moves.push_back({ -1, -1 });
    moves.push_back({ 1, -1 });
    moves.push_back({ -1, 1 });
    moves.push_back({ 1, 1 });

    return moves;
}

movelisttype Pawn::GetMoveList(unsigned int maxDistance)
{
    movelisttype moves;

    moves.push_back({ 2, 0 });
    moves.push_back({ 1, 0 });

    return moves;
}

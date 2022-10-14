// ChessPhone.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Piece.h"
#include "Pad.h"
#include "MoveMap.h"
#include "Validator.h"
#include <chrono>
using namespace std::chrono;


int main()
{
    MoveMapper::Initialize();

    vector<Piece *> pieces;
    pieces.push_back(new Queen());
    pieces.push_back(new Rook());
    pieces.push_back(new Bishop());
    pieces.push_back(new Knight());
    pieces.push_back(new King());
    pieces.push_back(new Pawn());
    Pad p(coord( 4,3 ), "123456789#0*");
    //SevenDigitPhoneNumberValidator v; 
    TenDigitPhoneNumberValidator v;

    Pawn k;
    auto mm = MoveMapper::GetMoveMapping(k, p, v);

    p.dump();

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for (auto piece : pieces)
    {
        auto legalmoves = MoveMapper::GetAllLegalMoves(*piece, p, v);
        cout << piece->GetName() << " => " << legalmoves << endl;
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    cout << "Execution time: " << time_span.count() << " seconds.";
    cout << endl;
}


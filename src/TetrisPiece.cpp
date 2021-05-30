#include <cmath>

#include "TetrisPiece.h"

TetrisPiece::TetrisPiece(vector<vector<vector<TileType>>> layout, int size, int pieceID) : size{ size }, layout{ layout }, pieceID{pieceID}
{
    numberOfRotations = static_cast<int>(layout.size());
}

vector<vector<TileType>> TetrisPiece::GetCurrentLayout() const
{
    return layout[currentRotation];
}

int TetrisPiece::GetSize() const
{
    return size;
}

int TetrisPiece::GetPieceID() const
{
    return pieceID;
}

void TetrisPiece::RotateClockwise()
{
    currentRotation++;
    currentRotation = currentRotation % numberOfRotations;
}

void TetrisPiece::RotateAntiClockwise()
{
    currentRotation--;
    currentRotation = abs(currentRotation % numberOfRotations);
}



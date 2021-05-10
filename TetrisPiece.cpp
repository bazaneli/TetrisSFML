#include <cmath>

#include "TetrisPiece.h"

TetrisPiece::TetrisPiece(vector<vector<vector<int>>> layout, int size) : size{ size }, layout{ layout }
{
    numberOfRotations = static_cast<int>(layout.size());
}

vector<vector<int>> TetrisPiece::GetCurrentLayout()
{
    return layout[currentRotation];
}

int TetrisPiece::GetSize()
{
    return size;
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



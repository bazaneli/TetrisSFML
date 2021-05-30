#pragma once
#include <vector>

#include "TileType.h"

using std::vector;

class TetrisPiece
{
private:
	vector<vector<vector<TileType>>> layout;
	int currentRotation{ 0 };
	int numberOfRotations{ 0 };
	int size{0};
	int pieceID {0};
public:
	TetrisPiece(vector<vector<vector<TileType>>> layout, int size, int pieceID);
	vector<vector<TileType>> GetCurrentLayout() const;
	int GetSize() const;
	int GetPieceID() const;

	void RotateClockwise();
	void RotateAntiClockwise();
};


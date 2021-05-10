#pragma once
#include <vector>

using std::vector;

class TetrisPiece
{
private:
	vector<vector<vector<int>>> layout;
	int currentRotation{ 0 };
	int numberOfRotations{ 0 };
	int size;
public:
	TetrisPiece(vector<vector<vector<int>>> layout, int size);
	vector<vector<int>> GetCurrentLayout();
	int GetSize();

	void RotateClockwise();
	void RotateAntiClockwise();
};


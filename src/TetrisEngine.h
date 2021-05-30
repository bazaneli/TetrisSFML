#pragma once

#include <cmath>

#include <vector>

#include "TetrisPiece.h"
#include "TetrisSettings.h"
#include "TetrisSoundEngine.h"
#include "TileType.h"

using std::vector;


class TetrisEngine
{
private:

	const int NUMBER_OF_PIECES = 7;

	bool isGameOver = false;

	int currentPoints = 0;
	
	int timeToFall;
	int timeToClearLine;

	int currentTime = 0;
	int timePassedCleaning = 0;

	int currentDx = 0;
	int currentDy = 0;

	int fallingSpeed = 1;

	int moveDirection = 0;
	
	vector<int> linesCompleted;

	bool isMarkedForRotation = false;

	bool shouldFallFaster = false;

	bool ShouldFall();
	bool ShouldMoveInX();
	void TryPerfomPieceFall();

	int GetMiddleOfField();

	void PerformScorePoints();
public:

	vector<TetrisPiece> vectorPieces;
	vector<vector<TileType>> board;

	TetrisSoundEngine& soundEngine;

	TetrisPiece& nextPiece;
	TetrisPiece& currentPiece;
	TetrisSettings& settings;

	TetrisEngine(int timeToFall, int timeToClearLine, TetrisSettings& settings, vector<TetrisPiece>& vectorPieces, vector<vector<TileType>>& board, TetrisSoundEngine& soundEngine) : timeToFall{ timeToFall }
		,timeToClearLine{ timeToClearLine }
		, settings{ settings }
		, vectorPieces{ vectorPieces}
		, board{ board}
		, soundEngine { soundEngine }
		,currentPiece { vectorPieces[rand() % NUMBER_OF_PIECES]}
		,nextPiece{ vectorPieces[rand() % NUMBER_OF_PIECES] }
	{
		currentDx = GetMiddleOfField();
	};
	bool IsValidPositionForPiece(TetrisPiece& piece, vector<vector<TileType>>& board, int posX, int posY);
	bool IsGameOver();
	void PerformTick();

	void SetMoveDirection(int direction);

	void TryRotatePiece();

	void TryToFallFaster();

	int GetCurrentDx();
	int GetCurrentDy();

	int GetCurrentScore();
};




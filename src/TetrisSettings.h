#pragma once
class TetrisSettings
{
public:
	TetrisSettings();

	int fieldWidth;
	int fieldHeight;
	int basePixelSize;
	int scoreInformationSize;

	int borderSize;

	int frameRateLimite;

	const int NumberOfPieces = 7;

	float spriteScale;
};


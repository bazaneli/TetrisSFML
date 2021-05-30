#pragma once

enum class TileType
{
	emptySpace = 0,
	pieceOnBoard = 1,
	border = 2,
	preExplosion = 8,
	explosion = 9
};

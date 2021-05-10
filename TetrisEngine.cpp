#include "TetrisEngine.h"

void TetrisEngine::PerformTick()
{
    currentTime++;

    if (ShouldFall())
    {
        currentTime = 0;
        TryPerfomPieceFall();
    }
    if (ShouldMoveInX())
    {
        if (IsValidPositionForPiece(currentPiece, board, currentDx + moveDirection, currentDy))
            currentDx += moveDirection;
        moveDirection = 0;
    }
    if (isMarkedForRotation)
    {
        currentPiece.RotateClockwise();
        if (!IsValidPositionForPiece(currentPiece, board, currentDx, currentDy))
        {
            currentPiece.RotateAntiClockwise();
        }
        isMarkedForRotation = false;
    }
    if (shouldFallFaster)
    {
        if (IsValidPositionForPiece(currentPiece, board, currentDx, currentDy + fallingSpeed))
        {
            currentDy += fallingSpeed;
        }
        shouldFallFaster = false;
    }
    if (!linesCompleted.empty())
    {
        PerformScorePoints();
    }
}

void TetrisEngine::TryPerfomPieceFall()
{
    if (IsValidPositionForPiece(currentPiece, board, currentDx, currentDy + fallingSpeed))
    {
        currentDy += fallingSpeed;
    }
    else
    {
        //lock piece
        for (int piecePositionY = 0; piecePositionY < currentPiece.GetSize(); piecePositionY++)
            for (int piecePositionX = 0; piecePositionX < currentPiece.GetSize(); piecePositionX++)
            {
                if (currentPiece.GetCurrentLayout()[piecePositionY][piecePositionX] != 0)
                    board[currentDy + piecePositionY][currentDx + piecePositionX] = currentPiece.GetCurrentLayout()[piecePositionY][piecePositionX];
            }

        //check for points
        for (int piecePositionY = 0; piecePositionY < currentPiece.GetSize(); piecePositionY++)
        {
            if (currentDy + piecePositionY < settings.fieldHeight - settings.borderSize)
            {
                bool formedALine = true;
                for (int x = settings.borderSize; x < settings.fieldWidth - settings.borderSize; x++)
                    if (board[currentDy + piecePositionY][x] == 0)
                    {
                        formedALine = false;
                        break;
                    }

                if (formedALine)
                {
                    for (int x = settings.borderSize; x < settings.fieldWidth - settings.borderSize; x++)
                        board[currentDy + piecePositionY][x] = 8;

                    linesCompleted.push_back(currentDy + piecePositionY);
                }
            }
        }

        //choose next piece
        currentDx = GetMiddleOfField();
        currentDy = 0;
        currentPiece = nextPiece;
        nextPiece = vectorPieces[rand() % NUMBER_OF_PIECES];
        
        soundEngine.PlayHitFloor();

        //game over
        isGameOver = !IsValidPositionForPiece(currentPiece, board, currentDx, currentDy);
    }
}

void TetrisEngine::PerformScorePoints()
{
    timePassedCleaning++;
    if (timePassedCleaning >= timeToClearLine / 2)
    {
        for (auto& l : linesCompleted)
        {
            for (int px = settings.borderSize; px < settings.fieldWidth - settings.borderSize; px++)
            {
                board[l][px] = 9;
            }
        }
    }
    if (timePassedCleaning >= timeToClearLine)
    {
        for (auto& l : linesCompleted)
        {
            for (int px = settings.borderSize; px < settings.fieldWidth - settings.borderSize; px++)
            {
                for (int py = l; py > 0; py--)
                    board[py][px] = board[py - 1][px];
            }

            timePassedCleaning = 0;
            
            currentPoints +=  static_cast<int>(pow(linesCompleted.size(), 2) * 10);
            soundEngine.PlayScoredPoint();
            linesCompleted.clear();
        }
    }
}

bool TetrisEngine::IsValidPositionForPiece(TetrisPiece& piece, vector<vector<int>>& board, int posX, int posY)
{
    for (int piecePositionY = 0; piecePositionY < piece.GetSize(); piecePositionY++)
    {
        for (int piecePositionX = 0; piecePositionX < piece.GetSize(); piecePositionX++)
        {
            if (piece.GetCurrentLayout()[piecePositionY][piecePositionX] == 1)
            {
                int boardY = piecePositionY + posY;
                int boardX = piecePositionX + posX;

                if (board[boardY][boardX] != 0)
                    return false;
            }
        }
    }
    return true;
}

int TetrisEngine::GetMiddleOfField()
{
    return ((settings.fieldWidth - settings.borderSize) / 2) + 1;
}

void TetrisEngine::SetMoveDirection(int direction)
{
    moveDirection = direction;
}

void TetrisEngine::TryRotatePiece()
{
    isMarkedForRotation = true;
}

void TetrisEngine::TryToFallFaster()
{
    shouldFallFaster = true;
}

int TetrisEngine::GetCurrentDx()
{
    return currentDx;
}

int TetrisEngine::GetCurrentDy()
{
    return currentDy;
}

int TetrisEngine::GetCurrentScore()
{
    return currentPoints;
}

bool TetrisEngine::IsGameOver()
{
    return isGameOver;
}

bool TetrisEngine::ShouldFall()
{
    return currentTime == timeToFall;
}

bool TetrisEngine::ShouldMoveInX()
{
    return moveDirection != 0;
}



#include <vector>
#include "TetrisPiece.h"

using std::vector;

std::vector<std::vector<int>> GenerateBoard(int fieldHeight, int fieldWidth, int borderSize)
{
    vector<std::vector<int>> board;

    for (int i = 0; i < fieldHeight; i++)
    {
        board.push_back({});
        for (int j = 0; j < fieldWidth; j++)
        {
            if (i >= fieldHeight - borderSize || j < borderSize || j >= fieldWidth - borderSize)
                board[i].push_back(2);
            else
                board[i].push_back(0);
        }
    }

    return board;
}

vector<TetrisPiece> GeneratePieces()
{
    vector<TetrisPiece> vectorPieces;

    TetrisPiece pieceOne(
        {
            { //first roation
                vector<int>({ 1,0,0,0 }),
                vector<int>({ 1,0,0,0 }),
                vector<int>({ 1,0,0,0 }),
                vector<int>({ 1,0,0,0 })
            },
         { //second roation
             vector<int>({ 1,1,1,1 }),
             vector<int>({ 0,0,0,0 }),
             vector<int>({ 0,0,0,0 }),
             vector<int>({ 0,0,0,0 })
         }
        }, 4);

    vectorPieces.push_back(pieceOne);

    TetrisPiece pieceTwo(
        {
            { //first roation
                vector<int>({ 0,0,0 }),
                vector<int>({ 0,1,0 }),
                vector<int>({ 1,1,1 }),
            },
              { //second roation
                  vector<int>({ 1,0,0 }),
                  vector<int>({ 1,1,0 }),
                  vector<int>({ 1,0,0 }),
              },
              { //third roation
                  vector<int>({ 1,1,1 }),
                  vector<int>({ 0,1,0 }),
                  vector<int>({ 0,0,0 }),
              },
              { //forth roation
                  vector<int>({ 0,0,1 }),
                  vector<int>({ 0,1,1 }),
                  vector<int>({ 0,0,1 }),
              }
        }, 3);

    vectorPieces.push_back(pieceTwo);

    TetrisPiece pieceThree(
        {
            { //first roation
                vector<int>({ 1,1 }),
                vector<int>({ 1,1 })
            },
        }, 2);

    vectorPieces.push_back(pieceThree);

    TetrisPiece pieceFour(
        {
            { //first roation
                vector<int>({ 1,0,0 }),
                vector<int>({ 1,0,0 }),
                vector<int>({ 1,1,0 }),
            },
              { //second roation
                  vector<int>({ 1,1,1 }),
                  vector<int>({ 1,0,0 }),
                  vector<int>({ 0,0,0 }),
              },
              { //third roation
                  vector<int>({ 0,1,1 }),
                  vector<int>({ 0,0,1 }),
                  vector<int>({ 0,0,1 }),
              },
              { //forth roation
                  vector<int>({ 0,0,0 }),
                  vector<int>({ 0,0,1 }),
                  vector<int>({ 1,1,1 }),
              }
        }, 3);

    vectorPieces.push_back(pieceFour);

    TetrisPiece pieceFourR(
        {
            { //first roation
                vector<int>({ 0,0,1 }),
                vector<int>({ 0,0,1 }),
                vector<int>({ 0,1,1 }),
            },
              { //second roation
                  vector<int>({ 0,0,0 }),
                  vector<int>({ 1,0,0 }),
                  vector<int>({ 1,1,1 }),
              },
              { //third roation
                  vector<int>({ 1,1,0 }),
                  vector<int>({ 1,0,0 }),
                  vector<int>({ 1,0,0 }),
              },
              { //forth roation
                  vector<int>({ 1,1,1 }),
                  vector<int>({ 0,0,1 }),
                  vector<int>({ 0,0,0 }),
              }
        }, 3);

    vectorPieces.push_back(pieceFourR);

    TetrisPiece pieceFive(
        {
            { //first roation
                vector<int>({ 0,1,1 }),
                vector<int>({ 1,1,0 }),
                vector<int>({ 0,0,0 }),
            },
              { //second roation
                  vector<int>({ 1,0,0 }),
                  vector<int>({ 1,1,0 }),
                  vector<int>({ 0,1,0 }),
              },
        }, 3);

    vectorPieces.push_back(pieceFive);

    TetrisPiece pieceFiveR(
        {
            { //first roation
                vector<int>({ 1,1,0 }),
                vector<int>({ 0,1,1 }),
                vector<int>({ 0,0,0 }),
            },
              { //second roation
                  vector<int>({ 0,0,1 }),
                  vector<int>({ 0,1,1 }),
                  vector<int>({ 0,1,0 }),
              },
        }, 3);

    vectorPieces.push_back(pieceFiveR);

    return vectorPieces;
}

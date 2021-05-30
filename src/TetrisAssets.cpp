#include <sstream>
#include <string>
#include <fstream>
#include <vector>

#include "TetrisPiece.h"

using std::vector;

std::vector<std::vector<TileType>> GenerateBoard(int fieldHeight, int fieldWidth, int borderSize)
{
    vector<std::vector<TileType>> board;

    for (int i = 0; i < fieldHeight; i++)
    {
        board.push_back({});
        for (int j = 0; j < fieldWidth; j++)
        {
            if (i >= fieldHeight - borderSize || j < borderSize || j >= fieldWidth - borderSize)
                board[i].push_back(TileType::border);
            else
                board[i].push_back(TileType::emptySpace);
        }
    }

    return board;
}

vector<TetrisPiece> GeneratePieces()
{
    vector<TetrisPiece> vectorPieces;
    std::ifstream inFile;
    inFile.open("assets/pieces.dat");
    
    std::string line;
    
    int baseChar = '0';

int pieceID = 0;
    while (std::getline(inFile, line))
    {
        int size = static_cast<int>(line[2])-baseChar;
        int rotations = static_cast<int>(line[4])-baseChar;
        
        //TetrisPiece tp;
        vector<vector<vector<TileType>>> pieceMatrixAndRotation;
        for(int i=0; i<rotations; i++)
        {
            vector<vector<TileType>> pieceMatrix;
            for(int j=0; j<size; j++)
            {
                std::getline(inFile, line);
                std::stringstream ss(line);

                vector<TileType> lineTile;
                for (int k; ss >> k;) 
                {
                    lineTile.push_back( k == 0 ? TileType::emptySpace : TileType::pieceOnBoard);
                    if (ss.peek() == ',')
                        ss.ignore();
                }
                pieceMatrix.push_back(lineTile);
            }
            pieceMatrixAndRotation.push_back(pieceMatrix);
        }
        vectorPieces.push_back(TetrisPiece(pieceMatrixAndRotation, size, pieceID));
        pieceID++;
    }

    inFile.close();
    
    return vectorPieces;
}

#include "TetrisPieceDwg.h"

void TetrisPieceDwg::LoadSprites()
{
    pieceTexture.loadFromFile("assets/square1.png");
    pieceSprite = sf::Sprite(pieceTexture);
}

void TetrisPieceDwg::Draw()
{
    for (int line = 0; line < engine.currentPiece.GetSize(); line++)
        for (int column = 0; column < engine.currentPiece.GetSize(); column++)
        {
            if (engine.currentPiece.GetCurrentLayout()[line][column] == 1)
            {
                pieceSprite.setPosition((float)(engine.GetCurrentDx() + column) * settings.basePixelSize, 
                    (float)(engine.GetCurrentDy() + line) * settings.basePixelSize);
                window.draw(pieceSprite);
            }

        }
}

TetrisPieceDwg::~TetrisPieceDwg()
{
}

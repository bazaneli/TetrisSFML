#include "TetrisPieceDwg.h"

void TetrisPieceDwg::LoadSprites()
{
    pieceTexture.loadFromFile("assets/square2.png");
    pieceSprite = sf::Sprite(pieceTexture);
    
}

void TetrisPieceDwg::Draw()
{
    pieceSprite.setTextureRect(sf::IntRect(this->engine.currentPiece.GetPieceID() *32, 0, 32, 32));

    for (int line = 0; line < engine.currentPiece.GetSize(); line++)
        for (int column = 0; column < engine.currentPiece.GetSize(); column++)
        {
            if (engine.currentPiece.GetCurrentLayout()[line][column] == TileType::pieceOnBoard)
            {
                pieceSprite.setPosition(
                    static_cast<float>((engine.GetCurrentDx() + column) * settings.basePixelSize), 
                    static_cast<float>((engine.GetCurrentDy() + line) * settings.basePixelSize)
                    );

                pieceSprite.setScale(settings.spriteScale, settings.spriteScale);   
                window.draw(pieceSprite);
            }

        }
}

TetrisPieceDwg::~TetrisPieceDwg()
{
}

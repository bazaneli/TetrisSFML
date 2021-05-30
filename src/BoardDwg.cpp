#include "BoardDwg.h"

void BoardDwg::LoadSprites()
{
    texture.loadFromFile("assets/square1.png");
    pieceSprite = sf::Sprite(texture);
    
    textureBorder.loadFromFile("assets/borders.png");
    borderSprite = sf::Sprite(textureBorder);
    
    textureCrack.loadFromFile("assets/cracking.png");
    crackSprite = sf::Sprite(textureCrack);
}

void BoardDwg::Draw()
{
    for (int line = 0; line < settings.fieldHeight; line++)
        for (int column = 0; column < settings.fieldWidth; column++)
        {
            sf::Sprite* spritePtr = nullptr;
            if (engine.board[line][column] == TileType::border)
            {
                spritePtr = &borderSprite;
            }
            else if (engine.board[line][column] == TileType::pieceOnBoard)
            {
                spritePtr = & pieceSprite;
            }
            else if (engine.board[line][column] == TileType::preExplosion)
            {
                crackSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
                spritePtr = &crackSprite;
            }
            else if (engine.board[line][column] == TileType::explosion)
            {
                crackSprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
                spritePtr = &crackSprite;
            }
            if(spritePtr != nullptr)
            {
                spritePtr->setScale(settings.spriteScale, settings.spriteScale);
                spritePtr->setPosition(
                        static_cast<float>(column * settings.basePixelSize),
                        static_cast<float>(line * settings.basePixelSize));
                window.draw(*spritePtr);
            }
        }
}

BoardDwg::~BoardDwg()
{
}

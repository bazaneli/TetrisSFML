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
            if (engine.board[line][column] == 2)
            {
                borderSprite.setPosition(
                    static_cast<float>(column * settings.basePixelSize),
                    static_cast<float>(line * settings.basePixelSize));
                window.draw(borderSprite);
            }
            else if (engine.board[line][column] == 1)
            {
                pieceSprite.setPosition(
                    static_cast<float>(column * settings.basePixelSize),
                    static_cast<float>(line * settings.basePixelSize));
                window.draw(pieceSprite);
            }
            else if (engine.board[line][column] == 8)
            {
                crackSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
                crackSprite.setPosition(
                    static_cast<float>(column * settings.basePixelSize),
                    static_cast<float>(line * settings.basePixelSize));
                window.draw(crackSprite);
            }
            else if (engine.board[line][column] == 9)
            {
                crackSprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
                crackSprite.setPosition(
                    static_cast<float>(column * settings.basePixelSize),
                    static_cast<float>(line * settings.basePixelSize));
                window.draw(crackSprite);
            }
        }
}

BoardDwg::~BoardDwg()
{
}

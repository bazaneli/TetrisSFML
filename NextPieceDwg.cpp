#include "NextPieceDwg.h"

void NextPieceDwg::LoadSprites()
{
    int xPos = (settings.fieldWidth + settings.borderSize) * settings.basePixelSize;
    int yPos = 2 * settings.basePixelSize;
    
    rectangle = sf::RectangleShape(sf::Vector2f(5 * 32, 6 * 32));
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setOutlineThickness(4.f);
    rectangle.setOutlineColor(sf::Color::White);
    
    rectangle.setPosition(
        static_cast<float>(xPos),
        static_cast<float>(yPos)
    );
    
    pieceTexture.loadFromFile("assets/square1.png");
    pieceSprite = sf::Sprite(pieceTexture);
}

void NextPieceDwg::Draw()
{
    window.draw(rectangle);

    for (int line = 0; line < engine.nextPiece.GetSize(); line++)
        for (int column = 0; column < engine.nextPiece.GetSize(); column++)
        {
            if (engine.nextPiece.GetCurrentLayout()[line][column] == 1)
            {
                int xPos = settings.fieldWidth + settings.borderSize + column + 1;
                int yPos = 7 + line - engine.nextPiece.GetSize();
                pieceSprite.setPosition(
                    static_cast<float>(xPos * settings.basePixelSize),
                    static_cast<float>(yPos * settings.basePixelSize)
                );
                window.draw(pieceSprite);
            }
        }
}

NextPieceDwg::~NextPieceDwg()
{
}

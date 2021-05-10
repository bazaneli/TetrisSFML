#include <iostream>
#include <memory>
#include <string>


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>


#include "TetrisPiece.h"
#include "TetrisEngine.h"
#include "TetrisSettings.h"

#include "BoardDwg.h"
#include "TetrisPieceDwg.h"
#include "NextPieceDwg.h"
#include "ScoreDwg.h"
#include "TetrisSoundEngine.h"

using std::vector;

vector<TetrisPiece> GeneratePieces();
vector<vector<int>> GenerateBoard(int fieldHeight, int fieldWidth, int borderSize);

int main()
{
    TetrisSettings settings;

    vector<TetrisPiece> vectorPieces = GeneratePieces();
    vector<vector<int>> board = GenerateBoard(settings.fieldHeight, settings.fieldWidth, settings.borderSize);

    TetrisSoundEngine soundEngine;

    TetrisEngine engine(20, 20, settings, vectorPieces, board, soundEngine);

    sf::RenderWindow window(
        sf::VideoMode( (settings.basePixelSize + settings.scoreInformationSize) * settings.fieldWidth ,
                        settings.basePixelSize * settings.fieldHeight), "Tetris!", sf::Style::Titlebar | sf::Style::Close);

    
    vector<std::unique_ptr<ItemDrawable>> drawablesVector;
    drawablesVector.push_back(std::move(std::make_unique<BoardDwg>(window, settings, engine)));
    drawablesVector.push_back(std::move(std::make_unique<TetrisPieceDwg>(window, settings, engine)));
    drawablesVector.push_back(std::move(std::make_unique<NextPieceDwg>(window, settings, engine)));
    drawablesVector.push_back(std::move(std::make_unique<ScoreDwg>(window, settings, engine)));
        
    //soundEngine.StartMusic();

    while (window.isOpen())
    {
        window.setFramerateLimit(settings.frameRateLimite);
        window.clear();

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Left:
                    engine.SetMoveDirection(-1);
                    break;
                case sf::Keyboard::Right:
                    engine.SetMoveDirection(1);
                    break;
                case sf::Keyboard::Down:
                    engine.TryToFallFaster();
                    break;
                case sf::Keyboard::Up:
                    engine.TryRotatePiece();
                    break;
                default:
                    break;
                }
            }
        }

        if (!engine.IsGameOver())
        {

            engine.PerformTick();

            for (auto& drawable : drawablesVector)
            {
                drawable->Draw();
            }

            window.display();
        }
    }
}


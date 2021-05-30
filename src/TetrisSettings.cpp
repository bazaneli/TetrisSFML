#include "TetrisSettings.h"
#include <SFML/Window/VideoMode.hpp>
#include <iostream>

TetrisSettings::TetrisSettings()
{
    auto currentVM = sf::VideoMode::getDesktopMode(); 

    if(currentVM.height <= 1080)
    {
        basePixelSize = 16;
        fieldWidth = 17;
        fieldHeight = 34;
        scoreInformationSize = 15;
        spriteScale = 0.5f;
    }
    else
    {
        basePixelSize = 32;
        
        fieldWidth = 17;
        fieldHeight = 34;
        
        scoreInformationSize = 15;
        spriteScale = 1.f;
    }
    borderSize = 2;

    frameRateLimite = 60;
}

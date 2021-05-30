#pragma once


#include <SFML/Graphics.hpp>

#include "TetrisSettings.h"
#include "TetrisEngine.h"

class ItemDrawable
{
protected:
	sf::RenderWindow& window;
	TetrisSettings& settings;
	TetrisEngine& engine;

public:
	ItemDrawable(sf::RenderWindow& windowRef, TetrisSettings& settings, TetrisEngine& engine) :
		window{ windowRef } , settings{ settings } , engine{ engine }
	{
	};

	virtual ~ItemDrawable() {};

	virtual void LoadSprites() = 0;
	virtual void Draw() = 0;
	
};


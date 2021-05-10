#pragma once

#include <SFML/Graphics.hpp>

#include "TetrisSettings.h"
#include "TetrisEngine.h"

#include "ItemDrawable.h"

class TetrisPieceDwg: public ItemDrawable
{
private:

	sf::Texture pieceTexture;
	sf::Sprite pieceSprite;

public:
	TetrisPieceDwg(sf::RenderWindow& windowRef, TetrisSettings& settings, TetrisEngine& engine) :
		ItemDrawable(windowRef, settings, engine)
	{
		LoadSprites();
	};

	void LoadSprites() override;
	void Draw() override;

	~TetrisPieceDwg();

};


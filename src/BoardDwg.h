#pragma once

#include <vector>

#include "ItemDrawable.h"

using std::vector;

class BoardDwg: public ItemDrawable
{
private:

	sf::Sprite crackSprite;
	sf::Sprite pieceSprite;
	sf::Sprite borderSprite;

	sf::Texture texture;
	sf::Texture textureBorder;
	sf::Texture textureCrack;
	
public:
	BoardDwg(sf::RenderWindow& windowRef, TetrisSettings& settings, TetrisEngine& engine) :
		ItemDrawable(windowRef, settings, engine)
	{
		LoadSprites();
	};

	void LoadSprites() override;
	void Draw() override;

	~BoardDwg();
};


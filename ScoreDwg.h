#pragma once
#include "ItemDrawable.h"
#include <sstream>
class ScoreDwg : public ItemDrawable
{
private:
	sf::Font font;
	sf::Text text;

public:
	ScoreDwg(sf::RenderWindow& windowRef, TetrisSettings& settings, TetrisEngine& engine) :
		ItemDrawable(windowRef, settings, engine)
	{
		LoadSprites();
	}

	void LoadSprites() override;
	void Draw() override;

	~ScoreDwg();
};


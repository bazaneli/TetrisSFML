#pragma once
#include "ItemDrawable.h"
class NextPieceDwg : public ItemDrawable
{
private:
	sf::Sprite pieceSprite;
	sf::Texture pieceTexture;
	sf::RectangleShape rectangle;
public:
	NextPieceDwg(sf::RenderWindow& windowRef, TetrisSettings& settings, TetrisEngine& engine) :
		ItemDrawable(windowRef, settings, engine)
	{
		LoadSprites();
	}

	void LoadSprites() override;
	void Draw() override;

	~NextPieceDwg();
};


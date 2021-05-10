#include "ScoreDwg.h"

void ScoreDwg::LoadSprites()
{
	font.loadFromFile("assets/Gidole-Regular.ttf");
	text.setFont(font);

	text.setFillColor(sf::Color::Blue);
	text.setStyle(sf::Text::Bold);
	text.setCharacterSize(64);
}

void ScoreDwg::Draw()
{
	std::ostringstream os;
	os << engine.GetCurrentScore();
	text.setString(os.str());

	text.setPosition(static_cast<float>(
		(settings.fieldWidth + settings.borderSize) * settings.basePixelSize),
		10 * 32);

	window.draw(text);
}

ScoreDwg::~ScoreDwg()
{
}

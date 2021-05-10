#pragma once

#include <SFML/Audio.hpp>

class TetrisSoundEngine
{
private:
	sf::Music music;
	
	sf::SoundBuffer bufferHitFloor;
	sf::SoundBuffer bufferScoredPoint;
	sf::Sound soundHitFloor;
	sf::Sound soundScoredPoint;
public:
	TetrisSoundEngine();
	void StartMusic();
	void PlayHitFloor();
	void PlayScoredPoint();
};


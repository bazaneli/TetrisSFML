#include "TetrisSoundEngine.h"

TetrisSoundEngine::TetrisSoundEngine()
{
    music.openFromFile("assets/song.ogg");
    music.setVolume(40.f);
    music.setLoop(true);

    bufferHitFloor.loadFromFile("assets/hit.flac");
    bufferScoredPoint.loadFromFile("assets/explosion.wav");

    soundHitFloor.setBuffer(bufferHitFloor);
    soundScoredPoint.setBuffer(bufferScoredPoint);
}

void TetrisSoundEngine::StartMusic()
{
    music.play();
}

void TetrisSoundEngine::PlayHitFloor()
{
    soundHitFloor.play();
}

void TetrisSoundEngine::PlayScoredPoint()
{
    soundScoredPoint.play();
}

#pragma once
#include <SFML/Audio.hpp>

class AudioManager
{
private:
	AudioManager() {};
public:
	static AudioManager& Instance() { static AudioManager _instance; return _instance; }
	~AudioManager();
};
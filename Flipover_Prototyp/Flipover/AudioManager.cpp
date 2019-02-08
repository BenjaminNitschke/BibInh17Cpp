#include "stdafx.h"
#include "AudioManager.h"

int main() 
{
	sf::Music music;

	if (!music.openFromFile("BFGDivision.ogg"))
		return -1;

	music.play();

	while (true)
	{

	}

}
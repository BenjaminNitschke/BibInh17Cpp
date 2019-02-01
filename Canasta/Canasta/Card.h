#pragma once
#include <memory>
#include "Sprite.h"




class Card
{
private:
	

public:
	std::shared_ptr<Sprite> cardGraphic;
	Card(std::string value, std::string color)
	{
		cardGraphic = std::make_shared<Sprite>(std::make_shared<Texture>(("./PNG/"+value+color+".png").c_str()),640,360);
	}
	~Card()
	{

	}
	
};
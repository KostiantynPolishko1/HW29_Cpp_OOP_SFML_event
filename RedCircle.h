#pragma once

#ifndef REDCIRCLE_H
#define REDCIRCLE_H

#include <SFML/Graphics.hpp>

class RedCircle final: public sf::CircleShape
{
	void initCircle()
	{
		this->setOutlineThickness(1);
		this->setPosition(sf::Vector2f(0.0f, 0.0f));
		this->setFillColor(sf::Color(255, 0, 0));
		this->setOutlineColor(sf::Color(255, 255, 255));
	}
public:

	RedCircle() {}

	RedCircle(float radius)
	{
		this->initCircle();
		this->setRadius(radius);
	}
}
;
#endif
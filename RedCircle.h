#pragma once

#ifndef REDCIRCLE_H
#define REDCIRCLE_H

#include <SFML/Graphics.hpp>

class RedCircle final: public sf::CircleShape
{
private:
	float centerX;
	float centerY;

	void initCircle()
	{
		this->setOutlineThickness(1);
		this->setPosition(sf::Vector2f(0.0f, 0.0f));
		this->setFillColor(sf::Color(255, 0, 0));
		this->setOutlineColor(sf::Color(255, 255, 255));
	}
public:

	RedCircle() : centerX{}, centerY{} {}

	RedCircle(float radius) : centerX{}, centerY{}
	{
		this->initCircle();
		this->setRadius(radius);
	}

	void setCenterX(float centerX) {
		this->centerX = centerX;
	}
	
	void setCenterY(float centerY) {
		this->centerY = centerY;
	}
}
;
#endif
#pragma once

#ifndef SFMLDRAWER_H
#define SFMLDRAWER_H

#include "SFML/Graphics.hpp"
#include "RedCircle.h"
#include <iostream>

class SFMLDrawer
{
private:
	bool flagCircle;

	sf::VideoMode windowSize;
	sf::String windowTitle;
	sf::RenderWindow window;
	sf::Color bgColor;
	sf::Event event;

#pragma region figures
	RedCircle circle;
	void updateShape(sf::Shape&);

#pragma endregion figures

	void HandleInput();
	void Update();
	void Draw();
	void centerShape(sf::Shape& );
	void moveShape(sf::Shape&);

public:
	SFMLDrawer() : 
		windowSize{500, 500},
		windowTitle{"SFML Drawer"},
		window(this->windowSize, this->windowTitle),
		bgColor{255, 255, 255},
		circle{30.0f},
		flagCircle{false},
		event{}
	{
		centerShape(circle);
	}

	void Run();
};
#endif
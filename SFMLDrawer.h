#pragma once

#ifndef SFMLDRAWER_H
#define SFMLDRAWER_H

#include "SFML/Graphics.hpp"

class SFMLDrawer
{
private:
	sf::VideoMode windowSize = {500, 500};
	sf::String windowTitle = "SFML Drawer";
	sf::Color bgColor = sf::Color(255, 255, 255);
	sf::RenderWindow window;

	void HandleInput();
	void Update();
	void Draw();

public:
	SFMLDrawer() : window(this->windowSize, this->windowTitle) {}

	void Run();
};
#endif
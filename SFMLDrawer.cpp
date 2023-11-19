#include "SFMLDrawer.h"

void SFMLDrawer::HandleInput() 
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void SFMLDrawer::Update() 
{

}

void SFMLDrawer::Draw() 
{
	this->window.clear(this->bgColor);
	this->window.display();
}

void SFMLDrawer::Run() 
{
	while (this->window.isOpen())
	{
		HandleInput();
		Update();
		Draw();
	}
}
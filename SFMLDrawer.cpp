#include "SFMLDrawer.h"

void SFMLDrawer::HandleInput() 
{
	while (this->window.pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window.close();
	}
}

void SFMLDrawer::Update() 
{
	updateCircle();
}

void SFMLDrawer::Draw() 
{
	this->window.clear(this->bgColor);

	if(this->flagCircle)
		this->window.draw(this->circle);

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

void SFMLDrawer::updateCircle()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		this->circle.setPosition(sf::Vector2f((float)this->event.mouseButton.x, (float)this->event.mouseButton.y));
		this->flagCircle = true;
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		this->flagCircle = false;

}
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
	updateShape(this->circle);
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

void SFMLDrawer::centerShape(sf::Shape& shape)
{
	shape.setOrigin(shape.getLocalBounds().width / 2, shape.getLocalBounds().height / 2);
}

void SFMLDrawer::moveShape(sf::Shape& shape) 
{
	shape.move((float)sf::Mouse::getPosition(this->window).x, (float)sf::Mouse::getPosition(this->window).y);
}

void SFMLDrawer::updateShape(sf::Shape& shape)
{
	sf::Vector2f offset;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
	{
		shape.setPosition(sf::Vector2f((float)this->event.mouseButton.x, (float)this->event.mouseButton.y));
		this->flagCircle = true;
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) 
	{
		if (sf::Mouse::getPosition(this->window).x >=0 && sf::Mouse::getPosition(this->window).x <= 500)		
			offset.x = (float)sf::Mouse::getPosition(this->window).x;

		if (sf::Mouse::getPosition(this->window).y >=0 && sf::Mouse::getPosition(this->window).y <= 500)		
			offset.y = (float)sf::Mouse::getPosition(this->window).y;

		//std::cout << sf::Mouse::getPosition(this->window).x << " | " << (float)sf::Mouse::getPosition(this->window).y << "\n";
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) 
	{
		offset.x = +1;
		offset.y = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		offset.x = 0;
		offset.y = +1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		offset.x = -1;
		offset.y = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) 
	{
		offset.x = 0;
		offset.y = -1;
	}

	shape.move(offset);
}

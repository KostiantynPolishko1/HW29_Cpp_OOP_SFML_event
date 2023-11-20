#include "SFMLDrawer.h"

void SFMLDrawer::HandleInput() 
{
	while (this->window.pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed) {
			cleanArr(this->arrCircle);
			this->flagCircle = false;
			this->window.close();
		}
		else if (this->event.type == sf::Event::MouseMoved) 
		{
			this->mousePosition.x = (float)event.mouseMove.x;
			this->mousePosition.y = (float)event.mouseMove.y;
		}
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
		for (size_t i = 0; i < this->count; i++)
			this->window.draw(*(this->arrCircle + i));

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
		this->circle.setCenterX((float)this->event.mouseButton.x);
		this->circle.setCenterY((float)this->event.mouseButton.y);

		append(this->arrCircle, this->circle, this->count);
		this->flagCircle = true;
		this->count++;
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) 
	{
		/*if ((sf::Mouse::getPosition(this->window).x >= 0 && sf::Mouse::getPosition(this->window).x <= 500) &&
			(sf::Mouse::getPosition(this->window).y >= 0 && sf::Mouse::getPosition(this->window).y <= 500)) 
		{
			offset.x = (float)sf::Mouse::getPosition(this->window).x;		
			offset.y = (float)sf::Mouse::getPosition(this->window).y;
			std::cout << sf::Mouse::getPosition(this->window).x << " | " << (float)sf::Mouse::getPosition(this->window).y << "\n";
		}*/
		
		sf::Vector2f shapePosition = shape.getPosition();
		sf::Vector2f direction = mousePosition - shapePosition;
		float distance = std::sqrt(direction.x*direction.x + direction.y*direction.y);

		sf::Vector2f normDirection = direction / distance;
		float moveSpeed = 500.0f;
		
		offset = normDirection * moveSpeed;
	}
	//else if (this->event.type == sf::Event::MouseWheelScrolled)
	//{
	//	std::cout
	//		<< this->event.mouseWheelScroll.delta << "\n";
	//}

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

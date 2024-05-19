#include "Face.h"
#include "Utility.h"
#include "../model/GameModel.h"
#include <iostream>

Face::Face(sf::RenderWindow* target, int number)
:window (target),
_number(number)
{
	float X, Y;
	
	X = 60.0;
	Y = 75.0;
	mShape.setSize(sf::Vector2f(X,Y));

	if (_number%2 == 0) {
		X = 5.0;
	}else{
		X = window->getSize().x - 5.0 - mShape.getSize().x;
	}
	int deltaY = 3-_number/2;
	Y = window->getSize().y - deltaY*(mShape.getSize().y + 30);
	//Y=200.0;

	mShape.setPosition(X, Y);

	mShape.setFillColor(sf::Color::Black);
	mShape.setOutlineColor(sf::Color::Green);
	mShape.setOutlineThickness(2);
}

void Face::setCallback(std::function<void(int)> callback)
{
    mCallback = callback;
}

void Face::handleInput()
{
	if (isClicked (sf::Mouse::Left)){
		mCallback(_number);
		std::cout<<_number<<std::endl;
	}
}

bool Face::isClicked(sf::Mouse::Button button)
{
	if (sf::Mouse::isButtonPressed(button))
	{
		int x = mShape.getPosition().x;
		int y = mShape.getPosition().y;
		sf::IntRect buttonRect(x, y, mShape.getSize().x, mShape.getSize().y);

		if(buttonRect.contains(sf::Mouse::getPosition()))
		{
			return true;
		}
	}
	return false;
}

void Face::draw()
{
	//window.draw(mSprite);
	window->draw(mShape);
	//window->draw(mText);
}


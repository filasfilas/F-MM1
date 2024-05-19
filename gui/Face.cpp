#include "Face.h"
#include "Utility.h"

Face::Face(sf::RenderWindow* target, int number)
:window (target),
_number(number)
{
	float X, Y;
	
	X = 60.0;
	Y= 75.0;
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
/*
void Face::setTextString(sf::String str){
	mText.setString(str);
}
*/

void Face::draw()
{
	//window.draw(mSprite);
	window->draw(mShape);
	//window->draw(mText);
}


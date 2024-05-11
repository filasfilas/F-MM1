#include "MessageBox.h"
#include "Utility.h"

MessageBox::MessageBox(sf::RenderWindow* target, int viewWidth, int viewHeight)
:window (target)
{
	float X, Y;
	X = viewWidth/2 - (5/14.0)*viewWidth;
	Y= viewHeight - 0.2*viewHeight;
	mShape.setPosition(X,Y);
	X = (5/7.0)*viewWidth;
	Y= 0.2*viewHeight;
	mShape.setSize(sf::Vector2f(X,Y));

	mShape.setFillColor(sf::Color::Black);
	mShape.setOutlineColor(sf::Color::Green);
	mShape.setOutlineThickness(2);
}

void MessageBox::setTextString(sf::String str){
	mText.setString(str);
}

void MessageBox::draw()
{
	//window.draw(mSprite);
	window->draw(mShape);
	window->draw(mText);
}


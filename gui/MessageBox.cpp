#include "MessageBox.h"
#include "Utility.h"

MessageBox::MessageBox(sf::RenderWindow* target, int viewWidth, int viewHeight)
:window (target)
,mText()
{
	float X, Y;
	X = viewWidth/2 - (5/14.0)*viewWidth;
	Y= viewHeight - 0.2*viewHeight;
	mShape.setPosition(X,Y);
	X = (5/7.0)*viewWidth;
	Y= 0.2*viewHeight;
	mShape.setSize(sf::Vector2f(X,Y));
//	centerOrigin(mShape);

	mShape.setFillColor(sf::Color::Black);
	mShape.setOutlineColor(sf::Color::Green);
	mShape.setOutlineThickness(2);

	mText.setPosition(viewWidth/2.0 ,mShape.getPosition().y);
	//centerOrigin(mText);

}

void MessageBox::setFont(sf::Font* font){
	mText.setFont(*font);
}

void MessageBox::setTextString(sf::String str){
	if (str != "")	mText.setString(str);
}

void MessageBox::clean(){
	mText.setString("");
}

void MessageBox::draw()
{
	//window.draw(mSprite);
	window->draw(mShape);
	window->draw(mText);
}


#include "Button.h"
#include "Utility.h"

Button::Button()
{
}

Button::Button(sf::Sprite sprite, sf::Text text, sf::Vector2f position)
:mSprite(sprite)
,mText(text)
,mPosition(position)
{
	mSprite.setPosition(position);
	mText.setPosition(position);
}

/*
void Button::setButton(sf::Sprite sprite, sf::Text text)
{
	mSprite = sprite;
	mText = text; 
	//centerOrigin(mText);
	mText.setPosition(mSprite.getPosition());
}
*/

void Button::setSize(sf::Vector2f size){
	mSize=size;
	sf::Vector2f mOldScale = mSprite.getScale();
	sf::Vector2f mOldSize, mNewScale;
	mOldSize.x = mSprite.getGlobalBounds().width;
	mOldSize.y = mSprite.getGlobalBounds().height;
	mNewScale.x = size.x / mSprite.getGlobalBounds().width;
	mNewScale.y = size.y / mSprite.getGlobalBounds().height;
	mSprite.setScale(mNewScale);
}

void Button::setTextAlign(HorizontalAlign horizAlign, VerticalAlign verAlign)
{
	textHorizAlign = horizAlign;
	textVertAlign = verAlign;
	if (textHorizAlign == HorizontalAlign::CENTER){
		centerOrigin(mText);
	}
}

void Button::setTextString(sf::String str){
	mText.setString(str);
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(mSprite);
	window.draw(mText);
}

bool Button::isClicked(sf::Mouse::Button button, const sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(button))
	{
		int x = mSprite.getPosition().x - mSprite.getOrigin().x;
		int y = mSprite.getPosition().y - mSprite.getOrigin().y;
		sf::IntRect buttonRect(x, y, mSprite.getGlobalBounds().width, mSprite.getGlobalBounds().height);

		if(buttonRect.contains(sf::Mouse::getPosition(window)))
		{
			return true;
		}
	}
	return false;
}

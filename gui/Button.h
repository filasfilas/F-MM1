#pragma once

#include "SFML/Graphics.hpp"

	enum class HorizontalAlign{
		LEFT,
		CENTER,
		RIGHT
	};

	enum class VerticalAlign{
		UP,
		CENTER,
		DOWN
	};

//button = Sprite with Text on it.  Sprite is a main object of a button
class Button
{
	public:

			Button();
			Button(sf::Sprite sprite, sf::Text text, sf::Vector2f position);
		
		void setSize(sf::Vector2f size);
		void setTextString(sf::String str);
		void setTextAlign(HorizontalAlign, VerticalAlign=VerticalAlign::CENTER);
		bool isClicked(sf::Mouse::Button button, const sf::RenderWindow& window);

		void draw(sf::RenderWindow& window);


	private:
		sf::Text	mText;
		sf::Sprite	mSprite;
		sf::Vector2f mPosition;
		sf::Vector2f mSize;

		HorizontalAlign textHorizAlign=HorizontalAlign::LEFT;
		VerticalAlign	textVertAlign=VerticalAlign::CENTER;
};

#pragma once

#include "SFML/Graphics.hpp"

class MessageBox
{
	public:

			MessageBox(sf::RenderWindow* target, int viewWidth, int viewHeight);

		void setFont(sf::Font* font);					
		void setTextString(sf::String str);
		void draw();

		void clean();


	private:
		sf::RenderWindow* 	window;
		sf::Text			mText;
		sf::RectangleShape	mShape;
};

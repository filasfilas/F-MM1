#pragma once

#include "SFML/Graphics.hpp"

class Face
{
	public:

			Face(sf::RenderWindow* target, int number);
					
		//void setTextString(sf::String str);
		void draw();


	private:
		sf::RenderWindow* 	window;
		int	_number;
		//sf::Text			mText;
		sf::RectangleShape	mShape;
};

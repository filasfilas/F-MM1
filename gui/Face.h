#pragma once

#include "SFML/Graphics.hpp"
#include <functional>

class Face
{
	public:

			Face(sf::RenderWindow* target, int number);
		void setCallback(std::function<void(int)> callback);
		void draw();
		void handleInput();

	private:
		sf::RenderWindow* 	window;
		int	_number;
		//sf::Text			mText;
		sf::RectangleShape	mShape;

		std::function<void(int)> mCallback;

		bool isClicked(sf::Mouse::Button button);
};

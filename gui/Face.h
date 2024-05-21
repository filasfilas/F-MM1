#pragma once

#include "SFML/Graphics.hpp"
#include "../core/Application.h"
#include <functional>

class Face
{
	public:

			Face(sf::RenderWindow* target, GlobalDataRef gData, int number);
		void setCallback(std::function<void(int)> callback);
		void draw();
		void handleInput();

	private:
		sf::RenderWindow* 	window;
		int	_number;
		//sf::Text			mText;
		GlobalDataRef _gData;
		sf::RectangleShape	mShape;
        //sf::Sprite	mSprite;

		std::function<void(int)> mCallback;

		bool isClicked(sf::Mouse::Button button);
};

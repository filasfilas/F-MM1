#pragma once

//#include <cmath>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>


template<typename T>
void centerOrigin(T& obj)
{
	sf::FloatRect bounds = obj.getLocalBounds();
	obj.setOrigin(bounds.width / 2, bounds.height / 2);
}

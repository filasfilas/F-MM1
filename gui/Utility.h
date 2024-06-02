#pragma once

#include <cmath>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>


template<typename T>
void centerOrigin(T obj)
{
	sf::FloatRect bounds = obj.getLocalBounds();
	obj.setOrigin(std::floor(bounds.width / 2), std::floor(bounds.height / 2));
}

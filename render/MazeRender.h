#pragma once
#include "SFML/Graphics.hpp"
#include "../model/ModelDefinitions.h"
#include <vector>
#include <string>
#include <cmath>

const float VIEW_ANGLE = 60*(M_PI/180); //in radians

class CrossPoint {
	public:
		float _xPos, _yPos, _dist;
		DIRECTION _dir;
		CrossPoint (float xPos, float yPos, float dist, DIRECTION dir);
};

class MazeRender
{
	public:
		MazeRender(sf::RenderWindow* target, int viewWidth, int viewHeight);
		void chooseMaze (std::vector<unsigned int> maze);
		void render(float xPos, float yPos, int angle);

	private:	
		float _xPos, _yPos, wallSpriteShift;
        	float _angle; //in radians
		int _viewWidth, _viewHeight;
		int wallSpriteId;
		sf::RenderWindow* _window;
		std::vector <unsigned int> _walls;
		std::vector <CrossPoint> _crossPoints;

		int get2Bits(int value, DIRECTION direction);
        	sf::Texture _textures[3];
        	sf::Sprite _sprite;
};

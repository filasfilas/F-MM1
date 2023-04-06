#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include <string>

enum DIRECTION {N = 0xC0, E = 0x30, S = 0xC, W = 0x3};

/*
class Wall
{
	public:
		Wall (sf::Vector2i p1, sf::Vector2i p2);
		Wall (unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);
		sf::Vector2i _p1, _p2; //points of a wall
		//Direction of sprite
};
*/

class CrossPoint {
	public:
		float _xPos, _yPos, _dist;
		DIRECTION _dir;
		CrossPoint (float xPos, float yPos, float dist, DIRECTION dir);
};

class MazeRenderer
{
	public:
		MazeRenderer(sf::RenderWindow* target, std::vector<unsigned int> maze);
		void render(float xPos, float yPos, int angle);

	private:	
		float _xPos, _yPos, wallSpriteShift;
		int _angle, wallSpriteId;
		sf::RenderWindow* _window;
		std::vector <unsigned int> _walls;
		std::vector <CrossPoint> _crossPoints;
		//const int CELL_SIZE = 32;
		//const int WALL_THICKNESS = 2;

		int get2Bits(int value, DIRECTION direction);
		//sf::Color getWallColor(int m1);
        	sf::Texture _textures[3];
        	sf::Sprite _sprite;
};

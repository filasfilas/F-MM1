#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include <string>
#include <cmath>

enum DIRECTION {N = 0xC0, E = 0x30, S = 0xC, W = 0x3};
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const float VIEW_ANGLE = 60*(M_PI/180); //in radians
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
        float _angle; //in radians
		int wallSpriteId;
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

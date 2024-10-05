#pragma once
#include "SFML/Graphics.hpp"
#include "../model/ModelDefinitions.h"
#include <vector>
#include <string>


//const float VIEW_ANGLE = 90*(M_PI/180); //in radians


class MazeRender
{
	public:
		MazeRender(sf::RenderWindow* target, int viewWidth, int viewHeight);
		void chooseMaze (std::vector<unsigned int> maze,  int mapId);
		void render(float posX, float posY, float dirX, float dirY, float planeX, float planeY);
        void update(float dt);

	private:
		const float VIEW_SCALE = 0.4;	
		float _posX, _posY, _dirX, _dirY, _planeX, _planeY;
		float wallSpriteShift=0, length, wallDistance;
		int _viewWidth, _viewHeight;
		int _mapId;
		int wallSpriteId;
		sf::RenderWindow* _window;
		std::vector <unsigned int> _walls;

		int get2Bits(int value, DIRECTION direction);
       	sf::Texture _textures[18];
       	sf::Texture _mapTextures[3];
       	sf::Sprite _sprite;
};

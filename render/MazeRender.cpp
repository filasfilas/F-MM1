#include "MazeRender.h"
#include <cmath>
#include <iostream>


int MazeRender::get2Bits(int value, DIRECTION direction) {
	int res=value;
	if (direction==N) res=res>>6;
	if (direction==S) res=res>>2;
	if (direction==W) res=res>>0;
	if (direction==E) res=res>>4;

	res=res&3;
	return res;
}

MazeRender::MazeRender (sf::RenderWindow* target, int viewWidth, int viewHeight)
:_window (target)
,_viewWidth(viewWidth)
,_viewHeight(viewHeight)
{}

void MazeRender::chooseMaze (std::vector<unsigned int> maze){
	_walls = maze;
    _textures[0].loadFromFile("media/images/walls/wall01.png"); 
    _textures[1].loadFromFile("media/images/walls/wall02.png"); 
    _textures[2].loadFromFile("media/images/walls/wall03.png"); 
}

void MazeRender::update(float dt){

}

void MazeRender::render (float posX, float posY, float dirX, float dirY, float planeX, float planeY){
	_posX=posX;
	_posY=posY;
	_dirX=dirX;
	_dirY=dirY;
	_planeX=planeX;
	_planeY=planeY;

	DIRECTION wallDir;



	int stepX, stepY;
	float rayDirX, rayDirY, deltaDistX, deltaDistY, sideDistX, sideDistY;


	for (int scanLine=0; scanLine<=_viewWidth; scanLine++){
		float scanX = (2.0* scanLine) / _viewWidth - 1;
		rayDirX = _dirX + _planeX * scanX;
		rayDirY = _dirY + _planeY * scanX;

		//length of a ray between grids (X and Y)
		if (rayDirX == 0) {deltaDistX = 1.0E30;}
		else {deltaDistX = std::abs(1.0/rayDirX);}
		if (rayDirY == 0) {deltaDistY = 1.0E30;}
		else {deltaDistY = std::abs(1.0/rayDirY);}


    		//maze cell
    		int mazeX = int(_posX);
    		int mazeY = int (_posY);

		//distance to next (first) intersection
		if (rayDirX<0){
			stepX = -1;
			sideDistX = (_posX - mazeX) * deltaDistX;
		}
		else {
			stepX = 1;
			sideDistX = (mazeX + 1 - _posX) * deltaDistX;
		}
		if (rayDirY<0){
			stepY = -1;
			sideDistY = (_posY - mazeY) * deltaDistY;
		}
		else {
			stepY = 1;
			sideDistY = (mazeY + 1 - _posY) * deltaDistY;
		}

		//look for intersection
		wallSpriteId = 0;
   
		while (wallSpriteId == 0){
			if (sideDistX < sideDistY){
				if (stepX >0) {wallDir = E;}
				else {wallDir = W;}
				wallSpriteId = get2Bits(_walls[16*mazeY+mazeX], wallDir);
				if (wallSpriteId == 0) {
					sideDistX += deltaDistX;
			    		mazeX += stepX;
				}
			}
			else{
				if (stepY >0) {wallDir = N;}
				else {wallDir = S;}
				wallSpriteId = get2Bits(_walls[16*mazeY+mazeX], wallDir);
				if (wallSpriteId == 0) {
			    		sideDistY += deltaDistY;
			    		mazeY += stepY;
				}

			}
			//wallSpriteId = get2Bits(_walls[16*mazeY+mazeX], wallDir);
		}
//std::cout<<wallSpriteId<<" "<< sideDistX<<" " <<sideDistY<<std::endl;

		//shortest distance to the wall. 
		if ((wallDir == E) || (wallDir == W)) {
			wallDistance = sideDistX;
			wallSpriteShift = _posY + wallDistance * rayDirY;
		}
		else  {
			wallDistance = sideDistY;
			wallSpriteShift = _posX + wallDistance * rayDirX;
		}
		wallSpriteShift -= std::floor(wallSpriteShift);

	    	//draw 3d sprite wall

	    	length = int (VIEW_SCALE * _viewHeight / wallDistance);

        	_sprite.setTexture(_textures[wallSpriteId-1]);
		sf::Vector2u textureSize = _textures[wallSpriteId-1].getSize();
        	_sprite.setTextureRect(sf::IntRect(int(wallSpriteShift*textureSize.x), 0, 1, textureSize.y));
		_sprite.setOrigin(0,0);
        	_sprite.setPosition(scanLine, _viewHeight/2-length/2);  
        	_sprite.setScale (sf::Vector2f(1.0, length/96));
        	_window->draw(_sprite);

	}

}

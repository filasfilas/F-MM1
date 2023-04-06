#include "MazeRenderer.h"
#include <cmath>
#include <algorithm>
#include <iostream>


CrossPoint::CrossPoint (float xPos, float yPos, float dist, DIRECTION dir)
: _xPos(xPos)
, _yPos(yPos)
, _dist(dist)
, _dir(dir)
{}

int MazeRenderer::get2Bits(int value, DIRECTION direction) {
	int res=value;
	if (direction==N) res=res>>6;
	if (direction==S) res=res>>2;
	if (direction==W) res=res>>0;
	if (direction==E) res=res>>4;

	res=res&3;
	return res;
}

MazeRenderer::MazeRenderer (sf::RenderWindow* target, std::vector<unsigned int> maze){
	_window = target;
	_walls = maze;
    _textures[0].loadFromFile("textures/wall01.png"); 
    _textures[1].loadFromFile("textures/wall02.png"); 
    _textures[2].loadFromFile("textures/wall03.png"); 

}


void MazeRenderer::render (float xPos, float yPos, int angle){
	_xPos=xPos;
	_yPos=yPos;
	_angle=angle;

	sf::RectangleShape line, viewline;
	//sf::CircleShape dot;

	for (int scan=-400; scan<=400; scan++){
		float ray = 0.075*scan;
		float xx, yy, dist, Ax, Ay, len;
		DIRECTION dir;
		//parametric line formula
		Ax = cos (M_PI*(_angle+ray)/180);
		Ay = sin (M_PI*(_angle+ray)/180);

		//points of crossing
		_crossPoints.clear();
		for (int i=0; i<=16; i++){
			//hor grid
			yy=i;
			dist = (yy-_yPos)/Ay;
			if (dist >=0) {
				xx=_xPos + Ax*dist;
				if (Ay<0.0) {dir=S;}
				else {dir=N;}
				_crossPoints.push_back(CrossPoint (xx, yy, dist, dir));
			}
			//ver grid
			xx=i;
			dist = (xx-_xPos)/Ax;
			if (dist >=0) {
				yy=_yPos + Ay*dist;
				if (Ax<0.0) {dir=W;}
				else {dir=E;}
				_crossPoints.push_back(CrossPoint (xx, yy, dist, dir));
			}
		}
		sort (_crossPoints.begin(), _crossPoints.end(), [](const CrossPoint& a, const CrossPoint& b) {return (a._dist < b._dist);});

		//find 1st touch
		while(_crossPoints.size()>1){
			CrossPoint dott = _crossPoints.front();
			//find maze cell
			int xx= int(dott._xPos);
			int yy= int(dott._yPos);
			if (dott._dir == N) {yy--;}
			if (dott._dir == E) {xx--;}
			//check if a wall at direction
			if(get2Bits(_walls[16*yy+xx], dott._dir) == 0){
				_crossPoints.erase(_crossPoints.begin()+0);
			}
			else {
                		wallSpriteId = get2Bits(_walls[16*yy+xx], dott._dir); //take wall sprite id
                		if ((dott._dir ==N) || (dott._dir ==S)) {wallSpriteShift = dott._xPos - int(dott._xPos);}
                		else  {wallSpriteShift = dott._yPos - int(dott._yPos);}
				_crossPoints.erase(_crossPoints.begin()+1, _crossPoints.end());
			}
		}
		

	//draw 3d sprite wall
	len = 350/(_crossPoints[0]._dist * cos (M_PI*ray/180));
        _sprite.setTexture(_textures[wallSpriteId-1]);
        _sprite.setTextureRect(sf::IntRect(int(wallSpriteShift*196), 0, 1, 96));
        _sprite.setPosition(400-scan, 300-len/2);  
        _sprite.setScale (sf::Vector2f(1.0, len/96));
        _window->draw(_sprite);

	}

}

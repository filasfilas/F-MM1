#include "MazeRenderer.h"
#include <cmath>
#include <algorithm>
#include <iostream>

Wall::Wall (sf::Vector2i p1, sf::Vector2i p2){
	_p1=p1;
	_p2=p2;
}

Wall::Wall (unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2){
	_p1.x=x1; _p1.y=y1;
	_p2.x=x2; _p2.y=y2;
}

CrossPoint::CrossPoint (float xPos, float yPos, float dist, std::string dir)
: _xPos(xPos)
, _yPos(yPos)
, _dist(dist)
, _dir(dir)
{}

int MazeRenderer::get2Bits(int value, std::string direction) {
	int res=value;
	if (direction=="N") res=res>>6;
	if (direction=="S") res=res>>2;
	if (direction=="W") res=res>>0;
	if (direction=="E") res=res>>4;

	res=res&3;
	return res;
}

sf::Color MazeRenderer::getWallColor(int m1){
	sf::Color res;
	if(m1==0) {res= sf::Color(0,0,0);}
	if(m1==1) {res= sf::Color(255,255,255);}
	if(m1==2){res= sf::Color(0,255,0);}	
	if(m1==3) {res= sf::Color(255,255,0);}

	return res;
}


MazeRenderer::MazeRenderer (sf::RenderWindow* target, std::vector<unsigned int> maze){
	_window = target;
	_walls = maze;
}


void MazeRenderer::render (float xPos, float yPos, int angle){
	_xPos=xPos;
	_yPos=yPos;
	_angle=angle;

	sf::RectangleShape line, viewline;
	sf::CircleShape dot;
/*
	//draw grid
	line.setFillColor(sf::Color(255,255,255));
	for (int i=0; i<17; i++){
		line.setPosition(0, 32*i-1);
		line.setSize (sf::Vector2f(512, 2));
		_window->draw(line);
	}
	for (int i=0; i<17; i++){
		line.setPosition(32*i-1, 0);
		line.setSize (sf::Vector2f(2, 512));
		_window->draw(line);
	}
*/
	//draw maze
	for (int i=0; i<256; i++){
		int xx = i%16;
		int yy = i/16;
		int mask1;

		//N wall
		mask1 = get2Bits(_walls[i], "N");
		line.setFillColor(getWallColor (mask1));
		line.setSize (sf::Vector2f(32, 2));
		line.setPosition(32*xx, 512-32*(yy+1)-1);
		_window->draw(line);
		
		//S wall
		mask1 = get2Bits(_walls[i], "S");	
		line.setFillColor(getWallColor (mask1));
		line.setSize (sf::Vector2f(32, 2));
		line.setPosition(32*xx, 512-32*(yy)-1);
		_window->draw(line);
		
		//W wall
		mask1 = get2Bits(_walls[i], "W");
		line.setFillColor(getWallColor (mask1));
		line.setSize (sf::Vector2f(2, 32));
		line.setPosition(32*xx-1, 512-32*(yy+1)-1);
		_window->draw(line);

		//E wall
		mask1 = get2Bits(_walls[i], "E");
		line.setFillColor(getWallColor (mask1));
		line.setSize (sf::Vector2f(2, 32));
		line.setPosition(32*(xx+1)-1, 512-32*(yy+1)-1);
		_window->draw(line);
	}



	//view sector

	viewline.setSize (sf::Vector2f (200, 2));
	viewline.setFillColor(sf::Color(255,0,0));
	viewline.setPosition(32*_xPos, (512-32*_yPos));
	viewline.setRotation(-_angle-30);
	_window->draw(viewline);
	viewline.setRotation(-_angle+30);
	_window->draw(viewline);


	for (int ray=-30; ray<=30; ray++){
		float xx, yy, dist, Ax, Ay;
		std::string dir;
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
				if (Ay<0.0) {dir="S";}
				else {dir="N";}
				_crossPoints.push_back(CrossPoint (xx, yy, dist, dir));
			}
			//ver grid
			xx=i;
			dist = (xx-_xPos)/Ax;
			if (dist >=0) {
				yy=_yPos + Ay*dist;
				if (Ax<0.0) {dir="W";}
				else {dir="E";}
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
			if (dott._dir == "N") {yy--;}
			if (dott._dir == "E") {xx--;}
			//check if a wall at direction
			if(get2Bits(_walls[16*yy+xx], dott._dir) == 0){
				_crossPoints.erase(_crossPoints.begin()+0);
			}
			else {
				_crossPoints.erase(_crossPoints.begin()+1, _crossPoints.end());
			}
		}
		//draw crossdots
		dot.setFillColor(sf::Color(255,255,0));
		dot.setRadius(3);
		dot.setPosition(32.0*_crossPoints[0]._xPos, 512- 32.0*_crossPoints[0]._yPos);
		_window->draw(dot);
	}

}

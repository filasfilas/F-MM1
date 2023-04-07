#include <cmath>
#include<fstream>
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "MazeRenderer.h"


int FramesPerSecond = 60; //частота обновления
int ANGLE_STEP = 3;
float MOVE_STEP = 0.05;
std::vector<unsigned int> walls;
DIRECTION _direction = E;
DIRECTION _nextDirection = E;

	int xPos = 1;
	int yPos = 0;
	float xPosRend= xPos+ 0.5;
	float yPosRend= yPos+ 0.5;
	int angleRend=0;
	int targetAngle;
	int targetX, targetY;
	int turnDirection = 0;
	
	bool _isMoving = false;	
	bool _isTurning = false;	
	int _movingCounter;

void loadMaze(int mazeId){
	const char* sourceFileName="MAZEDATA.DTA";
	unsigned char ch=0;	
	std::ifstream inf(sourceFileName, std::ios::binary);
	if (!inf) {std::cerr<<"Cant't open file "<<sourceFileName<< std::endl;}

	inf.seekg(512*mazeId);
	for (int yy=0; yy<16; yy++){
		for (int xx=0; xx<16; xx++){
			inf.read((char*)&ch, sizeof(ch)); walls.push_back(ch);
		}
	}
	inf.close();
}

void turn (int turnDir){
	turnDirection = turnDir;
	if ((_isMoving)||(_isTurning)) return;
	_isTurning = true;
	if (turnDir == 1) {
		if (_direction == N) {_nextDirection = W;}
		if (_direction == W) {_nextDirection = S;}
		if (_direction == S) {_nextDirection = E;}
		if (_direction == E) {_nextDirection = N;}
	}
	if (turnDir == -1) {
		if (_direction == N) {_nextDirection = E;}
		if (_direction == E) {_nextDirection = S;}
		if (_direction == S) {_nextDirection = W;}
		if (_direction == W) {_nextDirection = N;}
	}
	targetAngle = angleRend + 90*turnDirection;
}

void move (int deltaMove){
	if ((_isMoving)||(_isTurning)) return;
	_isMoving = true;
	targetX = xPos;
	targetY = yPos;
	if (_direction == E) {targetX += deltaMove;}
	if (_direction == N) {targetY += deltaMove;}
	if (_direction == W) {targetX -= deltaMove;}
	if (_direction == S) {targetY -= deltaMove;}
	_movingCounter = 20;//int(1/MOVE_STEP);
}


int main() {


	int mazeId =0;
	std::cout<<"Enter maze id (0-54): ";
	std::cin>>mazeId;
	std::cout<<std::endl;

	loadMaze(mazeId);


	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Render Test");
	window.setFramerateLimit(FramesPerSecond);
	MazeRenderer mazeRender(&window, walls);

	//основной цикл программы
 	while (window.isOpen())
    	{
		//Input
        	sf::Event event;
        	while (window.pollEvent(event))
        	{
	            if (event.type == sf::Event::Closed)  window.close();
        		if (event.type == sf::Event::KeyPressed)
        		{
		         	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {turn (1);}
		         	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){turn (-1);}
		         	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { move(1);}
		         	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { move(-1);}
			}
        	}
		
		//update		
			if (_isMoving){
				xPosRend = targetX - (targetX-xPos)*MOVE_STEP*_movingCounter +0.5;
				yPosRend = targetY - (targetY-yPos)*MOVE_STEP*_movingCounter +0.5;
				_movingCounter--;
				if(_movingCounter<=0){
					_isMoving = false;
					xPos = targetX;
					yPos = targetY;				
				}
			}
			if (_isTurning){
				angleRend += turnDirection*ANGLE_STEP;
				if (angleRend == targetAngle) {
					_isTurning = false; 
					_direction = _nextDirection;
					if (_direction==E) angleRend =0;
					if (_direction==N) angleRend =90;
					if (_direction==W) angleRend =180;
					if (_direction==S) angleRend =-90;
				}
			}

		//render	
	       	window.clear(sf::Color::Black);
		mazeRender.render(xPosRend, yPosRend, angleRend);
	       	window.display();
    	}

	return 0;

return 0;
}


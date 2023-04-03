#include <cmath>
#include<fstream>
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "MazeRenderer.h"

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;
int FramesPerSecond = 60; //частота обновления
int ANGLE_STEP = 2;
float MOVE_STEP = 0.05;
std::vector<unsigned int> walls;

void loadMaze(){
	const char* sourceFileName="MAZEDATA.DTA";
	unsigned char ch=0;	
	std::ifstream inf(sourceFileName, std::ios::binary);
	if (!inf) {std::cerr<<"Cant't open file "<<sourceFileName<< std::endl;}

	for (int yy=0; yy<16; yy++){
		for (int xx=0; xx<16; xx++){
			inf.read((char*)&ch, sizeof(ch)); walls.push_back(ch);
		}
	}
	inf.close();
}

int main() {
	float xPos=1.5;
	float yPos=0.5;
	int angle=0;
	float angleRad;

	loadMaze();


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
				angleRad = angle*M_PI/180;
		         	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {angle += ANGLE_STEP;angleRad = angle*M_PI/180;}
		         	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {angle -= ANGLE_STEP;angleRad = angle*M_PI/180;}
		         	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { 
					xPos += MOVE_STEP * cos(angleRad);
					yPos += MOVE_STEP * sin(angleRad);
				}
		         	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { 
					xPos -= MOVE_STEP * cos(angleRad);
					yPos -= MOVE_STEP * sin(angleRad);
				}
			}
        	}
		
		//update		

		//render	
	       	window.clear(sf::Color::Black);
		mazeRender.render(xPos, yPos, angle);
		
	       	window.display();
    	}

	return 0;

return 0;
}


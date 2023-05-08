#include "GameModel.h"
#include <iostream>

GameModel::GameModel() 
: _party()
, _map()
{
	//temporary Sorpigal start
	_posX = 8;
	_posY = 3;
	_mapId = 1;
	_direction = N;
}

void GameModel::setPosition(int X, int Y){
	_posX = X;
	_posY = Y;
	cellAction();
}

void GameModel::setDirection(DIRECTION dir){
	_direction = dir;
	cellAction();
}

bool GameModel::canMove (int dirX, int dirY){
	DIRECTION dir=NO_DIRECTION;
	if ((dirX==0)&&(dirY==1)) {dir = N;}
	if ((dirX==0)&&(dirY==-1)) {dir = S;}
	if ((dirX==1)&&(dirY==0)) {dir = E;}
	if ((dirX==-1)&&(dirY==0)) {dir = W;}

	if ((_map.getPassage(_posX, _posY) & dir) == 0) {return true;}
	else {return false;}
}

void GameModel::cellAction() {
	if (!_map.isSpecial(_posX, _posY)) {return;}
	//std::cout<<"Special!"<<std::endl;
}

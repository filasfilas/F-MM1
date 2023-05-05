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
}

void GameModel::setDirection(DIRECTION dir){
	_direction = dir;
}

bool GameModel::canMove (int dirX, int dirY){
	//temp just for town
/*
	if (forward_backward == 1){
		if ((_direction == N)&&(_posY==15)) return false;
		if ((_direction == S)&&(_posY==0)) return false;
		if ((_direction == E)&&(_posX==15)) return false;
		if ((_direction == W)&&(_posX==0)) return false;
	}
	if (forward_backward == -1){
		if ((_direction == S)&&(_posY==15)) return false;
		if ((_direction == N)&&(_posY==0)) return false;
		if ((_direction == W)&&(_posX==15)) return false;
		if ((_direction == E)&&(_posX==0)) return false;
	}
*/
	DIRECTION dir=NO_DIRECTION;
	if ((dirX==0)&&(dirY==1)) {dir = N;}
	if ((dirX==0)&&(dirY==-1)) {dir = S;}
	if ((dirX==1)&&(dirY==0)) {dir = E;}
	if ((dirX==-1)&&(dirY==0)) {dir = W;}

	if ((_map.getPassage(_posX, _posY) & dir) == 0) {return true;}
	else {return false;}
}
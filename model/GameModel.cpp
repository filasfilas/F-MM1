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

bool GameModel::canMove (int forward_backward){
	//temp just for town
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

//std::cout<<_map.getPassage(_posX, _posY)<<"  "<< _direction<<"   "<<std::endl;
	//if ((_map.getPassage(_posX, _posY) & _direction) != 0) return false;

	return true;
}
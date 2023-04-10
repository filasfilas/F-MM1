#include "GameModel.h"

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

bool GameModel::canMove (int newX, int newY){
	//temp just for town
	if ((newX <0)||(newX>15)) return false;
	if ((newY <0)||(newY>15)) return false;
	return true;
/*
	if ((dir == S)&&(currentY==0)) return false;
	if ((dir == E)&&(currentX==15)) return false;
	if ((dir == W)&&(currentX==0)) return false;

	return !((_passage[16*currentY+currentX]) && dir);
*/
}
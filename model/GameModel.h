#pragma once
#include <string>
#include <queue>

#include "party.h"
#include "maps/map.h"
#include "ModelDefinitions.h"

class GameModel
{
	public:
		GameModel();

		Party	_party;
		Map	_map;


		int _posX;
		int _posY;
		int _mapId;
		DIRECTION _direction;

		void setPosition(int X, int Y);
		void setDirection(DIRECTION dir);
		bool canMove(int dirX, int dirY);

	private:	
		void cellAction();

};

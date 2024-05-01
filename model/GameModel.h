#pragma once
#include <string>
#include <queue>

#include "party.h"
#include "items.h"
#include "maps/map.h"
#include "ModelDefinitions.h"

class GameModel
{
	public:
		GameModel();

		Party	_party;
		Map	_map;
		Items	_items;


		int _posX;
		int _posY;
		int _mapId;
		DIRECTION _direction;

		void setPosition(int X, int Y);
		void selectMap(int id);
		void setDirection(DIRECTION dir);
		bool canMove(int dirX, int dirY);

		bool equipItem (Character* character, int itemNumber);
		bool removeItem (Character* character, int itemNumber);
		bool transferItem (Character* sender, Character* receiver, int itemNumber);
		int dropItem (Character* character, int itemNumber);

	private:	
		void cellAction();
		bool _darkness;

};

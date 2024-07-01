#pragma once
#include <string>
#include <queue>
#include <vector>

#include "party.h"
#include "items.h"
#include "maps/map.h"
#include "ModelDefinitions.h"

enum GameMode {
    WALK,
    BATTLE,
    SHOP,
    NPC      
};

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
		bool canMove(DIRECTION dir);
		bool canMove(int dirX, int dirY);

		std::string getMessage();
		void		addMessage(std::string msg);

		bool equipItem (Character* character, int itemNumber);
		bool removeItem (Character* character, int itemNumber);
		bool transferItem (Character* sender, Character* receiver, int itemNumber);
		int dropItem (Character* character, int itemNumber);

	private:	
		void cellAction();
		//void update();
		bool _darkness;
		bool _encounterFlag;
		std::vector<std::string> _messageOutbox;
    
        GameMode _gameMode;

};

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

		int getPosX()const {return _posX;}
		int getPosY()const {return _posY;}
		DIRECTION getDirection() const {return _direction;}
		int getMapId()const {return _map.getCurrentId();}

		void turnLeft();
		void turnRight();
		bool moveForward();
		bool moveBackward();

		void setPosition(int X, int Y);
		void selectMap(int id);
		bool canMove(int dirX, int dirY);

		std::string getMessage();
		void addMessage(std::string msg);
		std::string getSignal();
		void addSignal(std::string msg);

		bool equipItem (Character* character, int itemNumber);
		bool removeItem (Character* character, int itemNumber);
		bool transferItem (Character* sender, Character* receiver, int itemNumber);
		int dropItem (Character* character, int itemNumber);

	private:	
		int _posX;
		int _posY;
		DIRECTION _direction;

		void setDirection(DIRECTION dir);
		bool canMove(DIRECTION dir);
		void cellAction();

		//void update();
		bool _darkness;
		bool _encounterFlag;
		std::vector<std::string> _messageOutbox;
		std::vector<std::string> _signalOutbox;
        GameMode _gameMode;
};

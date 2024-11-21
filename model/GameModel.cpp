#include "GameModel.h"
#include <iostream>
#include <ctime>

GameModel::GameModel() 
: _party()
, _map()
{
    _map.init(this);
    _gameMode = WALK;

	//temporary Sorpigal start
	_posX = 8;
	_posY = 3;
	//_mapId = 1;
	_direction = N;
	_darkness=false;

	std::srand(std::time(nullptr));
}

void GameModel::turnLeft(){
	DIRECTION newDir;
	if (_direction == N) newDir = W;
	if (_direction == W) newDir = S;
	if (_direction == S) newDir = E;
	if (_direction == E) newDir = N;
	setDirection (newDir);
}
void GameModel::turnRight(){
	DIRECTION newDir;
	if (_direction == N) newDir = E;
	if (_direction == E) newDir = S;
	if (_direction == S) newDir = W;
	if (_direction == W) newDir = N;
	setDirection (newDir);
}

void GameModel::setDirection(DIRECTION dir){
	_direction = dir;
	cellAction();
}

bool GameModel::moveForward(){
	int newX, newY;
	if (!canMove(_direction)) return false;

	if(_direction == N) newY= _posY+1;
	if(_direction == S) newY= _posY-1;
	if(_direction == W) newX= _posX-1;
	if(_direction == E) newX= _posX-1;
	setPosition(newX, newY);
	return true;
}

bool GameModel::moveBackward(){
	int newX, newY;
	DIRECTION newDir;
	if(_direction == N) {newDir= S; newY= _posY-1;}
	if(_direction == S) {newDir= N; newY= _posY+1;}
	if(_direction == W) {newDir= E; newX= _posX-1;}
	if(_direction == E) {newDir= W; newX= _posX+1;}
	if (!canMove(newDir)) return false;

	setPosition(newX, newY);
	return true;
}

void GameModel::setPosition(int X, int Y){
	_posX = X;
	_posY = Y;
	if (_posX < 0){
		_posX=15;
		_map.goNextMap (W);
	}
	else if (_posX > 15){
		_posX=0;
		_map.goNextMap (E);
	}
	else if (_posY < 0){
		_posY=15;
		_map.goNextMap (S);
	}
	else if (_posY > 15){
		_posY=0;
		_map.goNextMap (N);
	}


	_encounterFlag = false;
	int randSeed = _map.getEncounterRand();
	_encounterFlag = (std::rand()%randSeed == 1);

	cellAction();
}

void GameModel::selectMap(int id) {
	if ((id<0)&&(id>54)) return;
	_map.select(id);
}



bool GameModel::canMove (int dirX, int dirY){
	DIRECTION dir=NO_DIRECTION;
	if ((dirX==0)&&(dirY==1)) {dir = N;}
	if ((dirX==0)&&(dirY==-1)) {dir = S;}
	if ((dirX==1)&&(dirY==0)) {dir = E;}
	if ((dirX==-1)&&(dirY==0)) {dir = W;}

	canMove(dir);
}

bool GameModel::canMove(DIRECTION dir){
	std::string str;
	str = _map.getPassage(_posX, _posY, dir);
	if (str == "passage") {return true;}
	else {
		addMessage(str);
		return false;
	}
}

void GameModel::cellAction() {
//std::cout<<_posX<<"   " <<_posY<<"   " <<_direction<<"   "<<getMapId()<<std::endl;
	_messageOutbox.clear();
	_darkness=false;

	if (_map.isDarkCell(_posX, _posY)) {
		_darkness = _party.hasLight(true);
	}
	if (_map.isDarkMap() && !_party.hasLight(false)) {_darkness = true;}

	if (_map.isSpecial(_posX, _posY)) {
			addMessage("script here");
		    _map.doScript(_posX, _posY, _direction);
	}else{
		if (_encounterFlag){
			_encounterFlag = false;
			addMessage("ENCOUNTER!");
			//encounter code
			
		}
	}

	if (_party.isDead()){
	//TO DO:  if party is dead goto dead script
	}
}

void GameModel::addMessage(std::string msg){
	_messageOutbox.push_back(msg);
}
void GameModel::addSignal(std::string msg){
	_signalOutbox.push_back(msg);
}

std::string GameModel::getMessage() {
	std::string result = "";
	if(!_messageOutbox.empty()) {
		result = _messageOutbox.front();
		_messageOutbox.erase(_messageOutbox.begin());
	}

	return result;	
}

std::string GameModel::getSignal() {
	std::string result = "";
	if(!_signalOutbox.empty()) {
		result = _signalOutbox.front();
		_signalOutbox.erase(_signalOutbox.begin());
	}

	return result;	
}

bool GameModel::equipItem (Character* character, int itemNumber) {
	int itemID = character -> getBackpack (itemNumber);
	if (itemID == 0) return true; //nothing to equip
	if ((character -> getBackpack (5)) != 0) return true; //fully equipped
	if (!_items.isEquippable(itemID)) return true; //not equippable
	
	//TO DO   check restriction
	if ((character -> _class == CLASS_KNIGHT)&&(_items.isRestricted(itemID, RESTR_KNIGHT))) return true;
	if ((character -> _class == CLASS_PALADIN)&&(_items.isRestricted(itemID, RESTR_PALADIN))) return true;
	if ((character -> _class == CLASS_ARCHER)&&(_items.isRestricted(itemID, RESTR_ARCHER))) return true;
	if ((character -> _class == CLASS_CLERIC)&&(_items.isRestricted(itemID, RESTR_CLERIC))) return true;
	if ((character -> _class == CLASS_SORCERER)&&(_items.isRestricted(itemID, RESTR_SORCERER))) return true;
	if ((character -> _class == CLASS_ROBBER)&&(_items.isRestricted(itemID, RESTR_ROBBER))) return true;
	if ((character -> _alignment == ALIGN_EVIL)&&(_items.isRestricted(itemID, RESTR_EVIL))) return true;
	if ((character -> _alignment == ALIGN_GOOD)&&(_items.isRestricted(itemID, RESTR_GOOD))) return true;
	if ((character -> _alignment == ALIGN_NEUTRAL)&&(_items.isRestricted(itemID, RESTR_NEUTRAL))) return true;
	
	//check if incompatible items
	int tempID;
	for(int i = 0; i<6; i++){
		tempID = character -> getEquipped (i);
		if (tempID == 0) continue;
		if (_items.incompatible (itemID, tempID)) return true;
	}

	character -> equipItem(itemNumber);
	if ((_items.isArmor(itemID))|| (_items.isShield(itemID))) {
		character -> _AC._permanent += _items.getAC(itemID);
		character -> _AC._temporary += _items.getAC(itemID);
	}
	if ((_items.isWeapon(itemID))|| (_items.isTwoHanded(itemID))) {
		character -> _damage += _items.getDamage(itemID);
	}
	if (_items.isMissile(itemID)) {
		character -> _damageMissile += _items.getDamage(itemID);
	}
	return true;
}

bool GameModel::removeItem (Character* character, int itemNumber) {
	int itemID = character -> getEquipped (itemNumber);
	if (itemID == 0) return true; //nothing to remove	
	if (_items.isCursed (itemID)) return true; //can't remove cursed item
	
	character -> removeItem(itemNumber);
	if ((_items.isArmor(itemID))|| (_items.isShield(itemID))) {
		character -> _AC._permanent -= _items.getAC(itemID);
		character -> _AC._temporary -= _items.getAC(itemID);
	}
	if ((_items.isWeapon(itemID))|| (_items.isTwoHanded(itemID))) {
		character -> _damage -= _items.getDamage(itemID);
	}
	if (_items.isMissile(itemID)) {
		character -> _damageMissile -= _items.getDamage(itemID);
	}
	return true;
}

int GameModel::dropItem (Character* character, int itemNumber) {
	int itemID = character -> getBackpack(itemNumber);
	character -> dropItem(itemNumber);
	return itemID;
}

bool GameModel::transferItem (Character* sender, Character* receiver, int itemNumber) {
	if (receiver == sender) return false; //no transfer
	if (receiver -> getBackpack(5) !=0) return false; //receiver backpack is full
	if (sender -> _backpack.size() <= itemNumber) return false; // nothing to transfer
	int charges = sender -> _backpack_charges[itemNumber];
	receiver -> takeItem(sender -> dropItem(itemNumber), charges);
	return true;
}

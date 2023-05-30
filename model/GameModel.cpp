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

void GameModel::selectMap(int id) {
	if ((id<0)&&(id>54)) return;
	_mapId = id;
	_map.select(id);
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
	_map._scripts[_posX][_posY];
	//std::cout<<"Special!"<<std::endl;
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
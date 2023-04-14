#include "items.h"
#include <fstream>
#include <iostream>

Items::Items(){
    loadItemsData();
}

void Items::loadItemsData(){
    std::ifstream file(dataFileName, std::ios::in | std::ios::binary);
    if(!file){
        std::cerr<<"Cant't open file "<<dataFileName<< std::endl;
    }
    file.read((char*)&memblock, sizeof(memblock));
    file.close();
}


std::string Items::getName(int itemId){
	std::string name;
	for (int i=0; i<14; i++){
		name.push_back(memblock[24*(itemId-1) +i]);
	}
	return name;
}

unsigned int Items::getRestriction(int itemId) const{
	return memblock[24*(itemId-1) +14];
}

unsigned int Items::getBonus1_id(int itemId) const{
	return memblock[24*(itemId-1) +15];
}

unsigned int Items::getBonus1_value(int itemId) const{
	return memblock[24*(itemId-1) +16];
}

unsigned int Items::getBonus2_id(int itemId) const{
	return memblock[24*(itemId-1) +17];	
}


unsigned int Items::getBonus2_value(int itemId) const{
	if (getBonus2_id(itemId) != 0xff) {
		return memblock[24*(itemId-1) +18];
	}
	else return 0;
}

unsigned int Items::getSpell_id(int itemId) const{
	if (getBonus2_id(itemId) == 0xff) {
		return memblock[24*(itemId-1) +18];
	}
	else return 0;
}

unsigned int Items::getMaxCharges(int itemId) const{
	return memblock[24*(itemId-1) +19];
}

unsigned int Items::getCost(int itemId) const{
	return (memblock[24*(itemId-1) +21] + 256* memblock[24*(itemId-1) +20]);
}

unsigned int Items::getDamage(int itemId) const{
	return memblock[24*(itemId-1) +22];
}

unsigned int Items::getBonusDamage(int itemId) const{
	if ((isWeapon(itemId))||(isMissile(itemId))||(isTwoHanded(itemId))) {
		return memblock[24*(itemId-1) +23];}
	else return 0;
}

unsigned int Items::getAC(int itemId) const{
	if ((isArmor(itemId))||(isShield(itemId))) {
		return memblock[24*(itemId-1) +23];}
	else return 0;
}

bool Items::isCursed(int itemId) const{
	return (getBonus1_id(itemId) == 0xff);
}
bool Items::isEquippable(int itemId) const{
	return (getBonus1_id(itemId) != 1);
}
bool Items::isWeapon(int itemId) const{
	return (itemId <= 60);
}
bool Items::isMissile(int itemId) const{
	return ((itemId > 60)&&(itemId <= 85));
}
bool Items::isTwoHanded(int itemId) const{
	return ((itemId > 85)&&(itemId <= 120));
}
bool Items::isArmor(int itemId) const{
	return ((itemId > 120)&&(itemId <= 155));
}
bool Items::isShield(int itemId) const{
	return ((itemId > 155)&&(itemId <= 170));
}
bool Items::isMisc(int itemId) const{
	return (itemId > 170);
}
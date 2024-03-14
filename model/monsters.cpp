#include "monsters.h"
#include <fstream>
#include <iostream>

Monsters::Monsters(){
    loadMonstersData();
}

void Monsters::loadMonstersData(){
    std::ifstream file(dataFileName, std::ios::in | std::ios::binary);
    if(!file){
        std::cerr<<"Cant't open file "<<dataFileName<< std::endl;
    }
    file.read((char*)&memblock, sizeof(memblock));
    file.close();
}

std::string Monsters::getName(int monsterId){
	std::string name;
	for (int i=0; i<15; i++){
		name.push_back(memblock[32*(monsterId-1) +i]);
	}
	return name;
}


unsigned int Monsters::getMaxNumbers(int monsterId) const{
    return  memblock[32*(monsterId-1) +15];
}
unsigned int Monsters::getFriendliness (int monsterId) const{
    return  memblock[32*(monsterId-1) +16];
}
unsigned int Monsters::getBaseHP (int monsterId) const{
    return  memblock[32*(monsterId-1) +17];
}
unsigned int Monsters::getAC (int monsterId) const{
    return  memblock[32*(monsterId-1) +18];
}
unsigned int Monsters::getMaxDamage (int monsterId) const{
    return  memblock[32*(monsterId-1) +19];
}
unsigned int Monsters::getAttackNumbers (int monsterId) const{
    return  memblock[32*(monsterId-1) +20];
}
unsigned int Monsters::getSpeed (int monsterId) const{
    return  memblock[32*(monsterId-1) +21];
}
unsigned int Monsters::getExp (int monsterId) const{
    return memblock[32*(monsterId-1) +22] + 256*memblock[32*(monsterId-1) +23];
}
unsigned int Monsters::getLoot (int monsterId) const{
    return  memblock[32*(monsterId-1) +24] >>1;
}
unsigned int Monsters::getMagicResist (int monsterId) const{
    return  memblock[32*(monsterId-1) +25] &0x7f;
}
unsigned int Monsters::getResistFlags (int monsterId) const{
    return  memblock[32*(monsterId-1) +26];
}
unsigned int Monsters::getBonusOnTouch (int monsterId) const{
    return  memblock[32*(monsterId-1) +27] &0x7f;
}
unsigned int Monsters::getMissileDamage (int monsterId) const{
    return  memblock[32*(monsterId-1) +28] &0x7f;
}
unsigned int Monsters::getSpecialAttackId (int monsterId) const{
    return  memblock[32*(monsterId-1) +28] &0x7f;
}
unsigned int Monsters::getSpecialAttackLuck (int monsterId) const{
    return  memblock[32*(monsterId-1) +29];
}
unsigned int Monsters::getBravery (int monsterId) const{
    return  memblock[32*(monsterId-1) +30]&0x3f;
}
unsigned int Monsters::getSpriteId (int monsterId) const{
    return  memblock[32*(monsterId-1) +31];
}
/////////////   BOOLEAN   ////////////////////////////////////////////////////

bool Monsters::dropsGems (int monsterId) const{
	return (memblock[32*(monsterId-1) +24] &0x1) !=0;
}
bool Monsters::isUndead (int monsterId) const{
	return (memblock[32*(monsterId-1) +25]&0x80) != 0;
}
/* TO DO
bool Monsters::hasResistance (int monsterId, MONSTER_RESIST resist) const{

}
*/
bool Monsters::hasBonusOnTouch (int monsterId) const{
	return (memblock[32*(monsterId-1) +27]&0x80) != 0;
}
bool Monsters::hasMissile (int monsterId) const{
    return  (memblock[32*(monsterId-1) +28] &0x80) != 0;
}
bool Monsters::hasSpecAttack (int monsterId) const{
    return (memblock[32*(monsterId-1) +28] &0x80 ==0)&&(memblock[32*(monsterId-1) +28] != 0);
}
bool Monsters::canRegenerate (int monsterId) const{
	return (memblock[32*(monsterId-1) +30]&0x40) != 0;
}
bool Monsters::canAdvancePosition (int monsterId) const{
	return (memblock[32*(monsterId-1) +30]&0x80) != 0;
}



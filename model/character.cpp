#include "character.h"
#include <algorithm>

AttributePair::AttributePair() {
	_permanent= _temporary= 0;
}

Character::Character() {
	clear();
}

int Character::getStock (std::string stockType) const{
	if(stockType == "food") return _food;
	if(stockType == "gold") return _gold;
	if(stockType == "gems") return _gems;
	return 0;
}

void Character::addStock(std::string stockType, int value){
	if(stockType == "food") _food += value;
	if(stockType == "gold") _gold += value;
	if(stockType == "gems") _gems += value;
}

int Character::giveStock (std::string stockType) {
	return giveStock (stockType, getStock (stockType) );
}

int Character::giveStock (std::string stockType, int value) {
	if( value> getStock (stockType)) value = getStock (stockType);

	if(stockType == "food") {_food -= value; return value;}
	if(stockType == "gold") {_gold -= value; return value;}
	if(stockType == "gems") {_gems -= value; return value;}
	return 0;
}


Condition Character::getWorstCondition() const {
	if (_condition == 0xff) return ERADICATED;
	if ((_condition >>6) == 0x3) return DEAD;
	if ((_condition >>5) == 0x5) return STONED;
	if ((_condition & 0x40) != 0) return UNCONSCIOUS;
	if ((_condition & 0x20) != 0) return PARALYZED;
	if ((_condition & 0x10) != 0) return POISONED;
	if ((_condition & 0x8) != 0) return DISEASED;
	if ((_condition & 0x4) != 0) return SILENCED;
	if ((_condition & 0x2) != 0) return BLINDED;
	if ((_condition & 0x1) != 0) return ASLEEP;
	return GOOD;
}

int Character::getEquipped(int id) const {
	if (id>=_equipped.size()) return 0;
	return _equipped[id];
}

int Character::getBackpack(int id) const {
	if (id>=_backpack.size()) return 0;
	return _backpack[id];
}

int Character::dropItem(int itemNumber) {
// itemNumber is number in "backpack"
	if (itemNumber>=_backpack.size()) {return 0;}
	int itemId = _backpack[itemNumber];
	_backpack.erase(_backpack.begin()+itemNumber);
	_backpack_charges.erase(_backpack_charges.begin()+itemNumber);
	return itemId;
}

int Character::removeItem(int itemNumber) {
// itemNumber is number in "equipped". Return itemID or "0" if failed.
	if (itemNumber>=_equipped.size()) {return 0;}
	if (_backpack.size()>=6) {return 0;}

	int itemID = _equipped[itemNumber];
	_backpack.push_back(_equipped[itemNumber]);
	_backpack_charges.push_back(_equipped_charges[itemNumber]);
	_equipped.erase(_equipped.begin()+itemNumber);
	_equipped_charges.erase(_equipped_charges.begin()+itemNumber);
	return itemID;
}

void Character::equipItem(int itemNumber) {
// itemNumber is number in "backpack".
	if (itemNumber>=_backpack.size()) {return;}
	if (_equipped.size()>=6) {return;}
	_equipped.push_back(_backpack[itemNumber]);
	_equipped_charges.push_back(_backpack_charges[itemNumber]);
	_backpack.erase(_backpack.begin()+itemNumber);
	_backpack_charges.erase(_backpack_charges.begin()+itemNumber);
}

bool Character::takeItem(int newItem, int charges) {
	if (_backpack.size()>=6) return false;
	_backpack.push_back(newItem);
	_backpack_charges.push_back(charges);	
	return true;
}

bool Character::hasItem(int itemID){
	for (int i=0; i< _equipped.size(); i++){
		if(_equipped[i] == itemID) return true;
	}
	for (int i=0; i< _backpack.size(); i++){
		if(_backpack[i] == itemID) return true;
	}
	return false;
}


void Character::clear() {
	_name="";

	_class= CLASS_KNIGHT;
	_alignment= ALIGN_NEUTRAL;
	_sex= MALE;
	_race= HUMAN;

	_might._permanent = _might._temporary = 0;
	_intellect._permanent = _intellect._temporary = 0;
	_personality._permanent = _personality._temporary = 0;
	_endurance._permanent = _endurance._temporary = 0;
	_speed._permanent = _speed._temporary = 0;
	_accuracy._permanent = _accuracy._temporary = 0;
	_luck._permanent = _luck._temporary = 0;
	_level._permanent = _level._temporary = 0;

	_magicResistence._permanent = _magicResistence._temporary = 0;
	_fireResistence._permanent = _fireResistence._temporary = 0;
	_coldResistence._permanent = _coldResistence._temporary = 0;
	_electricityResistence._permanent = _electricityResistence._temporary = 0;
	_acidResistence._permanent = _acidResistence._temporary = 0;
	_fearResistence._permanent = _fearResistence._temporary = 0;
	_poisonResistence._permanent = _poisonResistence._temporary = 0;
	_sleepResistence._permanent = _sleepResistence._temporary = 0;

	_ageYears = 18;
	_ageDays = 0;
	_AC._permanent = _AC._temporary = 0;
	_spellLevel._permanent = _spellLevel._temporary = 0;
	_HP._permanent = _HP._temporary = 0;
	_SP._permanent = _SP._temporary = 0;

	_experience=_damage=0;
	_gold= _gems= _food= 0;
	_town= -1;

	for (int i=0; i<16; i++) {
		_skills[i]=0;
	}
	_condition = 0;

	for (int i=0; i<100; i++) {
		_spells[i]=false;
	}

	_equipped.clear();
	_backpack.clear();
	_equipped_charges.clear();
	_backpack_charges.clear();
}

bool Character::isDead() {
// so character cant do anything (ASLEEP, ERADICATED, DEAD, STONED, UNCONSCIOUS)
	if ((_condition & 0b11000001) != 0) return true;
	return false;
}

void Character::rest(){
	if (_condition & 0x80) return;
	resetSP();
	resetParameters();
	resetAC();
	resetResist();

	_condition = _condition & 0x98; // clear some conditions 
	if(_HP._temporary == 0) {_HP._temporary = 1;}
	_ageDays++;
	if (_ageDays > 255){
		_ageDays=0;
		_ageYears++;
	}

	int temp = 81 + rand()%70;
	if (_ageYears > temp){
		_condition = DEAD;
		return;
	}
	// to be continued 

}

void Character::resetParameters(){
	_intellect._temporary = _intellect._permanent;
	_might._temporary = _might._permanent;
	_personality._temporary = _personality._permanent;
	_endurance._temporary = _endurance._permanent;
	_speed._temporary = _speed._permanent;
	_accuracy._temporary = _accuracy._permanent;
	_luck._temporary = _luck._permanent;
	_level._temporary = _level._permanent;
	_spellLevel._temporary =_spellLevel._permanent;
}

void Character::resetResist(){
	_magicResistence._temporary = _magicResistence._permanent;
	_fireResistence._temporary =_fireResistence._permanent;
	_coldResistence._temporary = _coldResistence._permanent;
	_electricityResistence._temporary = _electricityResistence._permanent;
	_acidResistence._temporary = _acidResistence._permanent;
	_fearResistence._temporary = _fearResistence._permanent;
	_poisonResistence._temporary = _poisonResistence._permanent;
	_sleepResistence._temporary = _sleepResistence._permanent;
}

void Character::resetAC(){
	int tempAC = _AC._permanent;
	int spd = _speed._temporary;

	if (spd >= 40) {tempAC += 9;}
	else if ((spd < 40 )&&(spd >= 25)) {tempAC += (spd/5 + 1);}
	else if ((spd < 25 )&&(spd >= 21)) {tempAC += 5;}
	else if ((spd < 21 )&&(spd >= 13)) {tempAC += ((spd-1)/2 - 5);}
	else if ((spd < 13 )&&(spd >= 9)) {}
	else if ((spd < 9 )&&(spd >= 5)) {tempAC += ((spd-1)/2 - 4);}
	else if (spd < 5 ) {tempAC -= 3;}

	if (tempAC <0) {tempAC=0;}
	_AC._temporary = tempAC;
}

void Character::resetSP(){
	if (_spellLevel._temporary == 0) return;
	if ((_class == CLASS_PALADIN)&&(_level._temporary <7)) return;
	if ((_class == CLASS_ARCHER)&&(_level._temporary <7)) return;

	int tmpBase = 0;
	int tmpLvl = _level._temporary;
	if (_class == CLASS_CLERIC ) {tmpBase = _personality._temporary;}
	if (_class == CLASS_SORCERER ) {tmpBase = _intellect._temporary;}
	if (_class == CLASS_PALADIN ) {tmpBase = _personality._temporary; tmpLvl -= 6;}
	if (_class == CLASS_ARCHER ) {tmpBase = _intellect._temporary; tmpLvl -= 6;}	

	int factor = 3;
	if (tmpBase >= 40) {factor += 10;}
	else if ((tmpBase < 40 )&&(tmpBase >= 30)) {factor += (tmpBase/5 + 2);}	
	else if ((tmpBase < 30 )&&(tmpBase >= 21)) {factor += (tmpBase/3 - 2);}	
	else if ((tmpBase < 20 )&&(tmpBase >= 13)) {factor += ((tmpBase-1)/3 - 5);}	
	else if ((tmpBase < 13 )&&(tmpBase >= 9)) {}
	else if ((tmpBase < 9 )&&(tmpBase >= 5)) {factor += ((tmpBase-1)/2 - 4);}		
	else if (tmpBase < 5 ) {factor -= 3;}	

	if (factor<0) {factor=0;}

	_SP._permanent = factor * tmpLvl;
	_SP._temporary = _SP._permanent; 
}

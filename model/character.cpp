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
	_fireResistence._permanent = _fireResistence._temporary = 0;
	_coldResistence._permanent = _coldResistence._temporary = 0;
	_electricityResistence._permanent = _electricityResistence._temporary = 0;
	_poisonResistence._permanent = _poisonResistence._temporary = 0;
	_energyResistence._permanent = _energyResistence._temporary = 0;
	_magicResistence._permanent = _magicResistence._temporary = 0;
	_age._permanent = 18; _age._temporary = 0;
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


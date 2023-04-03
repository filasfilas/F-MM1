#include "character.h"
#include <algorithm>

AttributePair::AttributePair() {
	_permanent= _temporary= 0;
}

Character::Character() {
	clear();
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
	_conditions[0]= 1;

	for (int i=1; i<10; i++) {
		_conditions[i]=0;
	}
	for (int i=0; i<100; i++) {
		_spells[i]=false;
	}

	_equipped.clear();
	_backpack.clear();

}


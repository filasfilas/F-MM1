#pragma once
#include "character.h"
#include <vector>

enum Item_Restriction {
	ROBBER =1, SORCERER =2, CLERIC =4,
	ARCHER =8, PALADIN = 0x10, KNIGHT = 0x20,
	
	GOOD = 0x40, EVIL = 0x80, NEUTRAL = 0xC0	
};

class Item
{
	public:
		Item();
		std::string _name;
		unsigned int _restriction = 0;
		unsigned int _bonus1_id = 0;
		unsigned int _bonus1_value = 0;
		unsigned int _bonus2_id = 0;
		unsigned int _bonus2_value = 0;
		unsigned int _spell_id = 0;
		unsigned int _charges = 0;
		unsigned int _cost = 0;
		unsigned int _damage = 0;	
		unsigned int _bonusDamage = 0;
		unsigned int _AC = 0;

	private:

};

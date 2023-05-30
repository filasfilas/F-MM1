#pragma once
//#include "character.h"
#include <vector>
#include <string>

const int ITEMS_NUMBER = 255;

enum Item_Restriction {
	RESTR_ROBBER =1, RESTR_SORCERER =2, RESTR_CLERIC =4,
	RESTR_ARCHER =8, RESTR_PALADIN = 0x10, RESTR_KNIGHT = 0x20,
	
	RESTR_GOOD = 0x40, RESTR_EVIL = 0x80, RESTR_NEUTRAL = 0xC0	
};

class Items {
	public: 

		Items();

		std::string getName(int itemId);
		unsigned int getRestriction(int itemId) const;
		unsigned int getBonus1_id(int itemId) const;
		unsigned int getBonus1_value(int itemId) const;
		unsigned int getBonus2_id(int itemId) const;
		unsigned int getBonus2_value(int itemId) const;
		unsigned int getSpell_id(int itemId) const;
		unsigned int getMaxCharges(int itemId) const;
		unsigned int getCost(int itemId) const;
		unsigned int getDamage(int itemId) const;
		unsigned int getBonusDamage(int itemId) const;
		unsigned int getAC(int itemId) const;

		bool isCursed(int itemId) const;
		bool isEquippable(int itemId) const;
		bool isWeapon(int itemId) const;
		bool isMissile(int itemId) const;
		bool isTwoHanded(int itemId) const;
		bool isArmor(int itemId) const;
		bool isShield(int itemId) const;
		bool isMisc(int itemId) const;
		bool incompatible(int id1, int id2) const;
		bool isRestricted(int itemId, Item_Restriction restriction) const;

	private:
		void loadItemsData();
		const std::string   dataFileName = "data/mm1.dat";
		unsigned char memblock[6120]; 
};

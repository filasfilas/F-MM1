#pragma once
//#include "character.h"
#include <vector>
#include <string>

const int ITEMS_NUMBER = 255;

enum Item_Restriction {
	ROBBER =1, SORCERER =2, CLERIC =4,
	ARCHER =8, PALADIN = 0x10, KNIGHT = 0x20,
	
	GOOD = 0x40, EVIL = 0x80, NEUTRAL = 0xC0	
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

	private:
		void loadItemsData();
		const std::string   dataFileName = "data/mm1.dat";
		unsigned char memblock[6120]; 
};

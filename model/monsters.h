#pragma once
//#include "character.h"
#include <vector>
#include <string>

const int MONSTERS_NUMBER = 195;

/*
enum MONSTER_RESIST {
	MONRES_ASLEEP = 1, MONRES_FEAR = 2, MONRES_PARALYSIS = 4,
	MONRES_ENERGY = 8, MONRES_COLD = 0x10,
	MONRES_ELECTRICITY = 0x20, MONRES_FIRE = 0x40,
	MONRES_PHYSICAL_ATTACK = 0x80,
};
*/

class Monsters {
	public: 

		Monsters();

		std::string getName (int monsterId);
		unsigned int getMaxNumbers(int monsterId) const;
		unsigned int getFriendliness (int monsterId) const;
		unsigned int getBaseHP (int monsterId) const;
		unsigned int getAC (int monsterId) const;
		unsigned int getMaxDamage (int monsterId) const;
		unsigned int getAttackNumbers (int monsterId) const;
		unsigned int getSpeed (int monsterId) const;
		unsigned int getExp (int monsterId) const;
		unsigned int getLoot (int monsterId) const;
		unsigned int getMagicResist (int monsterId) const;
		unsigned int getResistFlags (int monsterId) const;
		unsigned int getBonusOnTouch (int monsterId) const;
		unsigned int getMissileDamage (int monsterId) const;
		unsigned int getSpecialAttackId (int monsterId) const;
		unsigned int getSpecialAttackLuck (int monsterId) const;
		unsigned int getBravery (int monsterId) const;
		unsigned int getSpriteId (int monsterId) const;

		bool dropsGems (int monsterId) const;
		bool isUndead (int monsterId) const;
		//bool hasResistance (int monsterId, MONSTER_RESIST resist) const;
		bool hasBonusOnTouch (int monsterId) const;
		bool hasMissile (int monsterId) const;
		bool hasSpecAttack (int monsterId) const;
		bool canRegenerate (int monsterId) const;
		bool canAdvancePosition (int monsterId) const;

	private:
		void loadMonstersData();
		const std::string   dataFileName = "data/monsters.dat";
		unsigned char memblock[195*32]; 
};

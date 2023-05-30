#pragma once
#include "character.h"
#include "roster.h"
#include <vector>

enum PARTY_PROTECTIONS{
	PARTY_PROTECTION_FEAR, PARTY_PROTECTION_COLD, PARTY_PROTECTION_FIRE,
	PARTY_PROTECTION_POISON, PARTY_PROTECTION_ACID, PARTY_PROTECTION_ELECTR,
	PARTY_PROTECTION_MAGIC, PARTY_PROTECTION_PHYSICAL,
	PARTY_LIGHT, PARTY_LEATHER_SKIN, PARTY_LEVITATE, PARTY_WATER_WALK,
	PARTY_GUARD_DOG, PARTY_BLESS, PARTY_INVISIBILITY, PARTY_SHIELD,
	PARTY_POWER_SHIELD, PARTY_CURSED,
	
	PARTY_PROTECTION_COUNT
};

class Party
{
	public:
		Party();
        bool	addCharacter(Character* newChar);
        void 	dismissCharacter(int id);
        Character*  getCharacter(int id);
		void	swapCharacters(int id1, int id2);

		void share(std::string stockType);
		int gatherAll(std::string stockType);
		void save();

		Roster	_roster;

	private:
		std::vector<Character*> _party;
		const int PARTY_SIZE = 6;
		int	_protections[PARTY_PROTECTION_COUNT];
};

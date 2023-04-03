#pragma once
#include "character.h"
#include <vector>

class Roster
{
	public:
		Roster();
        	void    loadRosterFile();
        	//void    importRosterFile();
        	void    saveRosterFile();
        	void    deleteCharacter(int id);
        	Character*  getCharacter(int id);

	private:
        	const std::string   rosterFileName = "save/ROSTER.DTA";
		std::vector<Character*> _roster;
		void readCharacter(int id);
		unsigned char memblock[2304]; 
};

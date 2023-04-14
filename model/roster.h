#pragma once
#include "character.h"
#include <vector>

class Roster
{
	public:
		Roster();
		~Roster();

		int	size() const;
        	void    loadRosterFile();
        	void    saveRosterFile();
        	void    deleteCharacter(int id);
        	void    addCharacter(Character* newChar);
        	Character*  getCharacter(int id);


	private:
        	const std::string   rosterFileName = "save/ROSTER.DTA";
		std::vector<Character*> _roster;
		void readCharacter(int id);
		void writeCharacter(int id);
		void writeEmptyCharacter(int id);
		unsigned char memblock[2304]; 
};

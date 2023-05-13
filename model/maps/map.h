#pragma once

#include <vector>
#include <functional>
#include "../ModelDefinitions.h"

class Map
{
	public:
		Map();
		void select (int id);
		std::vector<unsigned int> getWalls() const;
		unsigned int getPassage(int posX, int posY);
		bool isNonMagic(int posX, int posY);
		bool isDangerous(int posX, int posY);
		bool isDarkness(int posX, int posY);
		bool isSpecial(int posX, int posY);
		void clearSpecial(int posX, int posY);
		void reset();
		std::function<void()> _scripts[16][16];

	private:
		int _id;
		std::vector<unsigned int> _walls;	
		std::vector<unsigned int> _passage;
		std::vector<unsigned int> _regionWalls;
		unsigned int _constEncounters[16][16];

		void loadScripts();
		int getOffset (int posX, int posY);
};

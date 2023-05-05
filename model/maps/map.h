#pragma once

#include <vector>
#include "../ModelDefinitions.h"

class Map
{
	public:
		Map();
		void loadMap (int id);
		std::vector<unsigned int> getWalls() const;
		unsigned int getPassage(int posX, int posY);
		bool isNonMagic(int posX, int posY);
		bool isDangerous(int posX, int posY);
		bool isDarkness(int posX, int posY);
		bool isSpecial(int posX, int posY);
		void clearSpecial(int posX, int posY);
		void reset();
	private:
		int _id;
		std::vector<unsigned int> _walls;	
		std::vector<unsigned int> _passage;

};

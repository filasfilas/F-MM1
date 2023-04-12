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
	private:
		int _id;
		std::vector<unsigned int> _walls;	
		std::vector<unsigned int> _passage;

};

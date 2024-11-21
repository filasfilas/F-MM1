#pragma once

#include <vector>
#include <string>
#include <functional>
#include "../ModelDefinitions.h"
#include "mazelist.h"

class GameModel;

class Map
{
	public:
		Map();
        void init (GameModel* gm);
		void select (int id);
		std::vector<unsigned int> getWalls() const;
		std::string getPassage(int posX, int posY, DIRECTION dir);
		int getCurrentId () const {return _currentMapId;};
		void goNextMap (DIRECTION dir);

		bool isNonMagic(int posX, int posY);
		bool isDangerous(int posX, int posY);
		bool isDarkCell(int posX, int posY);
		bool isSpecial(int posX, int posY);
		void clearSpecial(int posX, int posY);
		bool isDarkMap();
		int	 getEncounterRand();

        void doScript(int posX, int posY, DIRECTION dir);

		void reset();


	private:
		int _currentMapId;
		Maze* _currentMaze;
		std::vector<unsigned int> _walls;	
		std::vector<unsigned int> _passage;
		std::vector<unsigned int> _regionWalls;
		std::vector<unsigned int> _regionPassage;
		std::vector<Maze*> _mazelist;

		int getOffset (int posX, int posY);
};

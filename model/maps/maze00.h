#pragma once

#include "maze.h"

class Maze00 : public Maze
{
	public:
		Maze00(GameModel* gm);
		void launchScript(int posX, int posY, DIRECTION dir);

	private:
        GameModel* _pGameModel;
};

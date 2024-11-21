#pragma once

#include "maze.h"

class Maze23 : public Maze
{
	public:
		Maze23(GameModel* gm);
	    void launchScript(int posX, int posY, DIRECTION dir);

	private:
        GameModel* _pGameModel;

		int _scriptXY[14] = {0xaa, 0xbf, 0xb9, 0xb7, 0xb5, 0x55, 0x57, 0x59, 0x88, 0x20, 0x74, 0x94, 0x8f, 0xa2};	
		int _scriptDirection[14] = {0xc0, 0x30, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3, 0x3, 0xff, 0xff, 0xff, 0xff};

        void entranceSorpigal();
        void gypsy();
        void pit();
        void teleport();
        void statue();
        void fountain();
        void avalanche();
        void entranceCrazeWizardCave();
        void chest();
        void encounter();
};

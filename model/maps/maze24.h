#pragma once

#include "maze.h"

class Maze24 : public Maze
{
	public:
		Maze24(GameModel* gm);
	    void launchScript(int posX, int posY, DIRECTION dir);

	private:
        	GameModel* _pGameModel;

		int _scriptXY[10] = {0x2c, 0xe6, 0x77, 0x27, 0x57, 0x68, 0x79, 0x36, 0x8, 0xa2};	
		int _scriptDirection[10] = {0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x30, 0x30};


        	void encounter();
        	void roadSign();
        	void wyvernPeaks();
        	void wyvernAttack();
        	void sign();
        	void hermit();
            void lordKilburn();
};

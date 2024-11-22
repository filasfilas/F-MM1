#pragma once

#include "maze.h"

class Maze22 : public Maze
{
	public:
		Maze22(GameModel* gm);
	    void launchScript(int posX, int posY, DIRECTION dir);

	private:
        	GameModel* _pGameModel;

		int _scriptXY[14] = {0xff, 0x9b, 0x83, 0x94, 0x75, 0x56, 0x77, 0x88, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea};	
		int _scriptDirection[14] = {0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

        	void rubyWhistle();
        	void encounter();
        	void roadSign();
        	void wagon();
        	void merchantPass();
        	void fountain();

};

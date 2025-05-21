#pragma once

#include "maze.h"


class Maze11 : public Maze
{
	public:
		Maze11(GameModel* gm);
		void launchScript(int posX, int posY, DIRECTION dir);

	private:
        	GameModel* _pGameModel;

		int _scriptXY[14] = {0x57, 0xb7, 0x17, 0x50, 0x5, 0x8, 0x36, 0x38, 0x6, 0x7, 0x9, 0x55, 0x59, 0xa8};	
		int _scriptDirection[14] = {0xcc, 0xff, 0xff, 0xc0, 0xc, 0xc, 0x3, 0x30, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};


	    void exitC4();

	    void volcanoGod();
        void virgin();
        void sign(std::string str); 

        void stabilizer();
        void lavaPit();
        void localAction();

	    void encounter();
};

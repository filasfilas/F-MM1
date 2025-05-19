#pragma once

#include "maze.h"


class Maze07 : public Maze
{
	public:
		Maze07(GameModel* gm);
		void launchScript(int posX, int posY, DIRECTION dir);

	private:
        	GameModel* _pGameModel;

		int _scriptXY[18] = {0x8, 0x0, 0x28, 0x68, 0x78, 0x32, 0x1c, 0x4, 0x3d, 0x2, 0x1e, 0x60, 0x3f, 0xec, 0xd4, 0xc0, 0xa0, 0xb5};	
		int _scriptDirection[18] = {0xc, 0xc, 0xc0, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};


	    void exitPortsmith();
	    void exitErliqDang();

        void bronzeGate();
        void sign(std::string str); 
        void genderPool();
        void poisonPool();
        void mightPool();
        void diseasePool();
        void treasurePool();

	    void localEncounter(int posX, int posY);
};

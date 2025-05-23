#pragma once

#include "maze.h"


class Maze16 : public Maze
{
	public:
		Maze16(GameModel* gm);
		void launchScript(int posX, int posY, DIRECTION dir);

	private:
       	GameModel* _pGameModel;
        bool _localFlag;

		int _scriptXY[8] = {0x97, 0x63, 0xff, 0xd4, 0xc6, 0x2a, 0xe, 0xbd};	
		int _scriptDirection[8] = {0xff, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

        void sign(std::string str); 

        void greatSeaBeast();
        void fortuneWheel();
        void resetFlag();

	    void encounter();
	    void localAction(int posX, int posY);
};

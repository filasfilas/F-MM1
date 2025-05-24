#pragma once

#include "maze.h"


class Maze21 : public Maze
{
	public:
		Maze21(GameModel* gm);
		void launchScript(int posX, int posY, DIRECTION dir);

	private:
       	GameModel* _pGameModel;
        bool _localFlag;

		int _scriptXY[8] = {0x78, 0xff, 0x28, 0x18, 0x6, 0x7, 0x8, 0x9};	
		int _scriptDirection[8] = {0xff, 0xff, 0xc, 0xff, 0xff, 0xff, 0xff, 0xff};

        void sign(std::string str); 

        void ghostShip();
        void triviaChance();
        void triviaIsland();
        void puzzle(int id);

	    void encounter();
	    void localAction(int posX, int posY);
};

#pragma once

#include "maze.h"


class Maze15 : public Maze
{
	public:
		Maze15(GameModel* gm);
		void launchScript(int posX, int posY, DIRECTION dir);

	private:
       	GameModel* _pGameModel;
        bool _dragonFlag;

		int _scriptXY[9] = {0xae, 0x3b, 0x2e, 0x4a, 0x42, 0x52, 0xf0, 0xa5, 0x7f};	
		int _scriptDirection[9] = {0x3, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3, 0x30, 0xff};

        void sign(std::string str); 

        void redDragon();
        void pirateSecretA();
        void pirateSecretB();
        void druid();
        void resetFlag();

	    void encounter();
	    void localAction(int posX, int posY);
	    void sea();
	    void lava();
};

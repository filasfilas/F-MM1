#pragma once

#include "maze.h"


class Maze20 : public Maze
{
	public:
		Maze20(GameModel* gm);
		void launchScript(int posX, int posY, DIRECTION dir);

	private:
       	GameModel* _pGameModel;
        bool _localFlag;

		int _scriptXY[9] = {0x33, 0x70, 0xd9, 0x2e, 0xc8, 0xc3, 0x69, 0xf9, 0xf3};	
		int _scriptDirection[9] = {0xc, 0xc3, 0x3, 0x30, 0x33, 0x33, 0x30, 0xff, 0xff};

	    void enterPortsmith();
	    void enterCavesKorin();
	    void enterCastleWhiteWolf();
	    void enterStronghEf1();

        void sign(std::string str); 

        void teleport();
        void blithesPeak();

	    void encounter();
	    void localAction(int posX, int posY);
};

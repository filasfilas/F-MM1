#pragma once

#include "maze.h"

class Maze25 : public Maze
{
	public:
		Maze25(GameModel* gm);
	    void launchScript(int posX, int posY, DIRECTION dir);

	private:
        	GameModel* _pGameModel;

		int _scriptXY[3] = {0xdd, 0x27, 0x47};	
		int _scriptDirection[3] = {0xff, 0xc, 0xff};


        	void portalFBG4();
        	void enterVolcano();

        	void nativesAttack();

        	void sign(std::string str);

        	void encounter();
        	void localAction(int posX, int posY);
};

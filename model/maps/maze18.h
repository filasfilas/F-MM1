#pragma once

#include "maze.h"


class Maze18 : public Maze
{
	public:
		Maze18(GameModel* gm);
		void launchScript(int posX, int posY, DIRECTION dir);

	private:
       	GameModel* _pGameModel;
        bool _localFlag;

		int _scriptXY[10] = {0x1d, 0x2b, 0xae, 0x5d, 0xce, 0x29, 0x9, 0xf4, 0x1e, 0x74};	
		int _scriptDirection[10] = {0x30, 0x30, 0xc, 0x30, 0x33, 0xcc, 0xcc, 0xc0, 0x3, 0xff};

	    void enterErliquin();
	    void enterCastleBlS();
	    void enterCastleBlN();
	    void enterWizardLair();
	    void enterErliquinDang();

        void sign(std::string str); 

        void gateMM2();
        void silverKey();

	    void encounter();
};

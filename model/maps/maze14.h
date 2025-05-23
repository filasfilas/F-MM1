#pragma once

#include "maze.h"


class Maze14 : public Maze
{
	public:
		Maze14(GameModel* gm);
		void launchScript(int posX, int posY, DIRECTION dir);

	private:
       	GameModel* _pGameModel;
        bool _secretEntranceFlag;

		int _scriptXY[6] = {0x25, 0x7f, 0xf7, 0x5e, 0xe7, 0x1c};	
		int _scriptDirection[6] = {0xff, 0xff, 0xc0, 0xc0, 0xc0, 0x3};


	    void enterFableCastle();
	    void secretEnterFableCastle();

        void sign(std::string str); 

        void darkRider();
        void localSwitch();
        void shrine();

	    void encounter();
};

#pragma once

#include "maze.h"


class Maze19 : public Maze
{
	public:
		Maze19(GameModel* gm);
		void launchScript(int posX, int posY, DIRECTION dir);

	private:
       		GameModel* _pGameModel;
        	bool _localFlag;

		int _scriptXY[6] = {0x44, 0x48, 0x99, 0x2d, 0x12, 0xf0};	
		int _scriptDirection[6] = {0x30, 0xc0, 0x3, 0x30, 0x3, 0xc0};

	    void enterMedusaLair();
	    void enterWarriorStr();


       	 void sign(std::string str); 

        void puzzle();

	    void encounter();
	    void localEncounter();
};

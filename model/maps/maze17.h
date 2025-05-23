#pragma once

#include "maze.h"


class Maze17 : public Maze
{
	public:
		Maze17(GameModel* gm);
		void launchScript(int posX, int posY, DIRECTION dir);

	private:
       	GameModel* _pGameModel;
        bool _localFlag;

		int _scriptXY[9] = {0xfe, 0x64, 0x24, 0xef, 0xdd, 0xbb, 0xb9, 0x9b, 0x76};	
		int _scriptDirection[9] = {0x3, 0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

        void sign(std::string str); 

        void teleport();
        void coralKey();

	    void encounter();
	    void localAction(int posX, int posY);
};

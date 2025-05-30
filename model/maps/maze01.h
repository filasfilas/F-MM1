#pragma once

#include "maze.h"

class Maze01 : public Maze
{
	public:
		Maze01(GameModel* gm);
		void launchScript(int posX, int posY, DIRECTION dir);

	private:
        	GameModel* _pGameModel;

		int _scriptXY[28] = {0xc3, 0x2c, 0xdc, 0xb2, 0xf1, 0x60, 0x6e, 0xd6, 0x8b, 0xf0, 0xb1, 0xec, 0xc1, 0x6d, 0xfe, 0x61, 0xe6, 0x31, 0x91, 0x35, 0x95, 0xe5, 0x39, 0x99, 0xe9, 0x3d, 0x9d, 0xed};	
		int _scriptDirection[28] = {0x30, 0xc0, 0xc, 0x30, 0xc0, 0x3, 0x30, 0xc, 0xff, 0xc0, 0x30, 0xc, 0x30, 0x30, 0xc0, 0x3, 0xc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

		void inn();
		void blacksmith();
		void market();
		void tavern();
		void temple();
		void training();

		void doorSign(int id);

		void exitB3();
		void downstairs();

		void succubus();
		void zam();

		void trap();
        void encounter();
};

#pragma once

#include <string>
//#include "../GameModel.h"
#include "../ModelDefinitions.h"
class GameModel;

class Maze
{
	public:
		virtual void launchScript(int posX, int posY, DIRECTION dir) = 0;

		std:: string _ovrName;
		std:: string _description;
		int	_scriptsCount;
	private:

};

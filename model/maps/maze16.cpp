#include "maze16.h"
#include "../GameModel.h"


Maze16::Maze16(GameModel* gm){
	_ovrName = "areaA3";
	_description = "areaA3";
	_scriptsCount = 8;
   	_pGameModel = gm;

    _localFlag = false;
}

void Maze16::launchScript(int posX, int posY, DIRECTION dir){

	//search for script number
	int position = posX + 16*posY;
	int scriptNumber = -1;
	for (int i =0; i< _scriptsCount; i++){
		if (position == _scriptXY[i]){
			scriptNumber = i;
		}
	}
	
	if ((scriptNumber > -1)&&(!(dir & _scriptDirection[scriptNumber]))){
		scriptNumber = -99;
	} 

    //int scriptNumber = getScriptNumber(int posX, int posY, DIRECTION dir);
    switch (scriptNumber){
	    case -1: localAction(posX, posY); break;
        case 0: greatSeaBeast(); break;
        case 1: fortuneWheel(); break;
        case 2: resetFlag(); break;
        case 3:  
        case 4: 
        case 5: 
        case 6: 
        case 7: encounter(); break;
        default: break;
    }

}

void Maze16::greatSeaBeast(){
    _pGameModel -> addMessage("greatSeaBeast");
    _localFlag = true;
}

void Maze16::fortuneWheel(){
    _pGameModel -> addMessage("fortuneWheel");
}

void Maze16::resetFlag(){
    _localFlag = false;
    _pGameModel -> addMessage("resetFlag");
}

void Maze16::sign(std::string str){
    _pGameModel -> addMessage(str);
}


 // to do encounter
void Maze16::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}

void Maze16::localAction(int posX, int posY){
    _pGameModel -> addMessage("sea");
}


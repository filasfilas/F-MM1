#include "maze25.h"
#include "../GameModel.h"

Maze25::Maze25(GameModel* gm){
	_ovrName = "areaC4";
	_description = "area C4";
	_scriptsCount = 10;
    	_pGameModel = gm;

}

void Maze25::launchScript(int posX, int posY, DIRECTION dir){
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

    switch (scriptNumber){
	case -1: localAction(posX, posY); break;
        case 0: portalFBG4(); break;
        case 1: enterVolcano(); break;
        case 2: nativesAttack(); break;
        default: break;
    }

}


void Maze25::portalFBG4(){
    _pGameModel -> addMessage("PORTAL OF POWER, ENTER (Y/N)?");
    _pGameModel -> selectMap(53);
    _pGameModel -> setPosition(12,4);
}

void Maze25::enterVolcano(){
    _pGameModel -> addMessage("A LARGE SLAB OF CORAL BLOCKS");
    _pGameModel -> selectMap(11);
    _pGameModel -> setPosition(7, 5);
}

void Maze25::nativesAttack(){
    _pGameModel -> addMessage("nativesAttack");
}


void Maze25::sign(std::string str){
    _pGameModel -> addMessage(str);
}


 // to do encounter
void Maze25::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}

void Maze25::localAction(int posX, int posY){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}

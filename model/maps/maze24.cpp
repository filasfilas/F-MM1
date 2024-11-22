#include "maze24.h"
#include "../GameModel.h"

Maze24::Maze24(GameModel* gm){
	_ovrName = "areaC3";
	_description = "area C3";
	_scriptsCount = 10;
    	_pGameModel = gm;

}

void Maze24::launchScript(int posX, int posY, DIRECTION dir){
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
	case -1: encounter(); break;
        case 0: roadSign(); break;
        case 1: lordKilburn(); break;
        case 2: wyvernPeaks(); break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7: wyvernAttack(); break;
        case 8: sign(); break;
        case 9: hermit(); break;
        default: break;
    }

}


 // to do encounter
void Maze24::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}

void Maze24::roadSign(){
    _pGameModel -> addMessage("ROADSIGN: SORPIGAL N.22, W.2, N.2");
}

void Maze24::lordKilburn(){
    _pGameModel -> addMessage("lord Kilburn");
}

void Maze24::wyvernPeaks(){
    _pGameModel -> addMessage("wyvernPeaks");
}

void Maze24::wyvernAttack(){
    _pGameModel -> addMessage("wyvern Attack");
}

void Maze24::sign(){
    _pGameModel -> addMessage("PAINTED IN A BLACK AND WHITE...");
}

void Maze24::hermit(){
    _pGameModel -> addMessage("hermit");
}

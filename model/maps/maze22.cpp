#include "maze22.h"
#include "../GameModel.h"

Maze22::Maze22(GameModel* gm){
	_ovrName = "areaC1";
	_description = "area C1";
	_scriptsCount = 14;
    _pGameModel = gm;

}

void Maze22::launchScript(int posX, int posY, DIRECTION dir){
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
        case 0: rubyWhistle(); break;
        case 1: roadSign(); break;
        case 2: 
        case 3: wagon(); break;
        case 4: merchantPass(); break;
        case 5:
        case 6:
        case 7: wagon(); break;
        case 8: 
        case 9: 
        case 10:
        case 11: 
        case 12: 
        case 13: fountain(); break;
        default: break;
    }

}

void Maze22::rubyWhistle(){
    _pGameModel -> addMessage("Ruby Whistle");
}

void Maze22::roadSign(){
    _pGameModel -> addMessage("ROADSIGN: SORPIGAL S.17, W.1, N.2");
}

void Maze22::wagon(){
    _pGameModel -> addMessage("wagon");
}

void Maze22::merchantPass(){
    _pGameModel -> addMessage("merchantPass");
}


void Maze22::fountain(){
    _pGameModel -> addMessage("fountain");
}

 // to do encounter
void Maze22::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}

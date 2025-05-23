#include "maze17.h"
#include "../GameModel.h"


Maze17::Maze17(GameModel* gm){
	_ovrName = "areaA4";
	_description = "areaA4";
	_scriptsCount = 9;
   	_pGameModel = gm;

    _localFlag = false;
}

void Maze17::launchScript(int posX, int posY, DIRECTION dir){

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
        case 0: sign("ATOP THIS PEAK 5 ISLANDS CAN BE SEEN TO THE SOUTHEAST"); break;
        case 1: teleport(); break;
        case 2: coralKey(); break;
        case 3:  
        case 4: 
        case 5: 
        case 6: 
        case 7: 
        case 8: encounter(); break;
        default: break;
    }

}

void Maze17::teleport(){
    _pGameModel -> addMessage("A WOODEN BRIDGE EXTENDES ACROSS");
}

void Maze17::coralKey(){
    _pGameModel -> addMessage("coralKey");
}


void Maze17::sign(std::string str){
    _pGameModel -> addMessage(str);
}


 // to do encounter
void Maze17::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}

void Maze17::localAction(int posX, int posY){
    _pGameModel -> addMessage("sea");
}


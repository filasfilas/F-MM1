#include "maze14.h"
#include "../GameModel.h"


Maze14::Maze14(GameModel* gm){
	_ovrName = "areaA1";
	_description = "areaA1";
	_scriptsCount = 6;
   	_pGameModel = gm;

    _secretEntranceFlag = false;
}

void Maze14::launchScript(int posX, int posY, DIRECTION dir){

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
	    case -1: encounter(); break;
        case 0: darkRider(); break;
        case 1: localSwitch(); break;
        case 2: enterFableCastle(); break;
        case 3: sign("CARVED ON A BLOCK OF ICE ARE THE WORDS: START AT 15-7 AND WALK TO DOOM!"); break; 
        case 4: secretEnterFableCastle(); break;
        case 5: shrine(); break;
        default: break;
    }

}

void Maze14::enterFableCastle(){
    _pGameModel -> addMessage("THE FABELED CASTLE DOOM!  WILL YOU ENTER (Y/N)?");
    _pGameModel -> selectMap(34);
    _pGameModel -> setPosition(7, 0);
}

void Maze14::secretEnterFableCastle(){
    if(!_secretEntranceFlag) return;
    _pGameModel -> addMessage("A SECRET PASSAGE TO DOOM, TAKE IT (Y/N)?");
    _pGameModel -> selectMap(34);
    _pGameModel -> setPosition(4, 4);
}

void Maze14::darkRider(){
    _pGameModel -> addMessage("dark Rider");
}

void Maze14::localSwitch(){
    _secretEntranceFlag = true;
    _pGameModel -> addMessage("switch");
}

void Maze14::shrine(){
    _pGameModel -> addMessage("THE POOL OF HEALTH GRANTS THOSE WHO ARE WORTHY +4 ENDURANCE!");
}


void Maze14::sign(std::string str){
    _pGameModel -> addMessage(str);
}


 // to do encounter
void Maze14::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}


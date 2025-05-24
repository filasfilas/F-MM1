#include "maze19.h"
#include "../GameModel.h"


Maze19::Maze19(GameModel* gm){
	_ovrName = "areaB2";
	_description = "areaB2";
	_scriptsCount = 6;
   	_pGameModel = gm;

    _localFlag = false;
}

void Maze19::launchScript(int posX, int posY, DIRECTION dir){

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
        case 0: puzzle(); break;
        case 1: enterMedusaLair(); break;
        case 2: enterWarriorStr(); break;
        case 3:  sign("CARVED ON A TREE: 9-9 RAVENS LAIR"); break;
        case 4:
        case 5: localEncounter(); break; 
        default: break;
    }

}

void Maze19::puzzle(){
    _pGameModel -> addMessage("ON A THRONE ADORNED");

}

void Maze19::enterMedusaLair(){
    _pGameModel -> addMessage("THERE'S A CAVE HERE, ENTER (Y/N)?");
    _pGameModel -> selectMap(13);
    _pGameModel -> setPosition(8, 0);
}

void Maze19::enterWarriorStr(){
    _pGameModel -> addMessage("A DESCENDING STAIRCASE IS THE ENTRANCE TO A WARRIORS STRONGHOLD, GO IN (Y/N)?");
    _pGameModel -> selectMap(39);
    _pGameModel -> setPosition(7, 1);
}

void Maze19::sign(std::string str){
    _pGameModel -> addMessage(str);
}


 // to do encounter
void Maze19::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}

void Maze19::localEncounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}



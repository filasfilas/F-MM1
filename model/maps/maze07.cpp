#include "maze07.h"
#include "../GameModel.h"


Maze07::Maze07(GameModel* gm){
	_ovrName = "cave3";
	_description = "Portsmith Dungeon";
	_scriptsCount = 18;
   	_pGameModel = gm;
}

void Maze07::launchScript(int posX, int posY, DIRECTION dir){

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
	    case -1: localEncounter(posX, posY); break;
        case 0: exitPortsmith(); break;
        case 1: exitErliqDang(); break;
        case 2: bronzeGate(); break;
        case 3: sign("DEMONS IN CONFERENCE, DO NOT DISTURB!"); break;
        case 4: 
        case 5: 
        case 6: 
        case 7:  
        case 8: 
        case 9: 
        case 10: 
        case 11: 
        case 12: localEncounter(posX, posY); break;
        case 13: genderPool(); break;
        case 14: poisonPool(); break;
        case 15: mightPool(); break;
        case 16: diseasePool(); break;
        case 17: treasurePool(); break;
        default: break;
    }

}

void Maze07::exitPortsmith(){
    _pGameModel -> addMessage("STAIRS GOING UP! TAKE THEM (Y/N)?");
    _pGameModel -> selectMap(1);
    _pGameModel -> setPosition(0, 15);
}

void Maze07::exitErliqDang(){
    _pGameModel -> addMessage("BLUE AND WHITE PORTAL, ENTER (Y/N)?");
    _pGameModel -> selectMap(8);
    _pGameModel -> setPosition(2, 7);
}

void Maze07::bronzeGate(){
    _pGameModel -> addMessage("BRONZE GRATE REPELS YOU!");
}

void Maze07::sign(std::string str){
    _pGameModel -> addMessage(str);
}

void Maze07::genderPool(){
    _pGameModel -> addMessage("Gender Pool");
}

void Maze07::poisonPool(){
    _pGameModel -> addMessage("Poison Pool");
}

void Maze07::mightPool(){
    _pGameModel -> addMessage("Might Pool");
}

void Maze07::diseasePool(){
    _pGameModel -> addMessage("Desease Pool");
}

void Maze07::treasurePool(){
    _pGameModel -> addMessage("Treasure Pool");
}

 // to do encounter
void Maze07::localEncounter(int posX, int posY){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}


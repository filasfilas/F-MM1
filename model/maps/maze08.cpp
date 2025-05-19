#include "maze08.h"
#include "../GameModel.h"


Maze08::Maze08(GameModel* gm){
	_ovrName = "cave4";
	_description = "Erliquin Dungeon";
	_scriptsCount = 18;
   	_pGameModel = gm;
}

void Maze08::launchScript(int posX, int posY, DIRECTION dir){

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
        case 0: exitErliquin(); break;
        case 1: exitB1(); break;
        case 2: passwd(); break;
        case 3: passwd(); break;
        case 4:
        case 5: teleport(posX, posY); break;
        case 6: 
        case 7: powerShield(); break; 
        case 8:  
        case 9:   
        case 10:  
        case 11: sign("DANCING LIGHTS FLICKER..."); break;  
        case 12: 
        case 13: 
        case 14: 
        case 15: 
        case 16: 
        case 17: 
        case 18:
        case 19: powerShield(); break; 
        case 20:
        case 21:
        case 22:
        case 23: treasure(); break; 
        default: break;
    }

}

void Maze08::exitErliquin(){
    _pGameModel -> addMessage("STAIRS GOING UP! TAKE THEM (Y/N)?");
    _pGameModel -> selectMap(4);
    _pGameModel -> setPosition(15, 7);
}

void Maze08::exitB1(){
    _pGameModel -> addMessage("STAIRS GOING UP! TAKE THEM (Y/N)?");
    _pGameModel -> selectMap(18);
    _pGameModel -> setPosition(13, 1);
}

void Maze08::passwd(){
    _pGameModel -> addMessage("COVERED WITH FLASHING LIGHTS...");
}

void Maze08::sign(std::string str){
    _pGameModel -> addMessage(str);
}

void Maze08::teleport(int posX, int posY){
    _pGameModel -> setPosition(0, posY);
}

void Maze08::powerShield(){
    _pGameModel -> addMessage("ZAP!");
}

void Maze08::treasure(){
    _pGameModel -> addMessage("treasure");
}


 // to do encounter
void Maze08::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}


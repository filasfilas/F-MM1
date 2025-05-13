#include "maze04.h"
#include "../GameModel.h"


Maze04::Maze04(GameModel* gm){
	_ovrName = "Erliquin";
	_description = "Erliquin";
	_scriptsCount = 22;
    	_pGameModel = gm;
}

void Maze04::launchScript(int posX, int posY, DIRECTION dir){

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
	    case -1: treasure(); break;
        case 0: inn(); break;
        case 1: agar(); break;
        case 2: blacksmith(); break;
        case 3: market(); break;
        case 4: exitB1(); break;
        case 5: tavern(); break;
        case 6: temple(); break;
        case 7: training(); break;
        case 8: teleport(); break;
        case 9: downstairs(); break;
        case 10:
        case 11: 
        case 12: doorSign(scriptNumber); break;
        case 13: golem(); break; 
        case 14: golem(); break;
        case 15: golem(); break;
        case 16: golem(); break;
        case 17: golem(); break;
        case 18: doorSign(scriptNumber); break;
        case 19: golem(); break; 
        case 20:
        case 21: doorSign(scriptNumber); break;
        default: break;
    }

}

void Maze04::inn(){
    _pGameModel -> addMessage("INN");
}

void Maze04::blacksmith(){
    _pGameModel -> addMessage("BLACKSMITH");
}

void Maze04::market(){
    _pGameModel -> addMessage("MARKET");
}

void Maze04::tavern(){
    _pGameModel -> addMessage("TAVERN");
}

void Maze04::temple(){
    _pGameModel -> addMessage("TEMPLE");
}

void Maze04::training(){
    _pGameModel -> addMessage("TRAINING");
}

void Maze04::doorSign(int id){
	std::string str;
	switch (id){
		case 10: str = "FOUR STAR FOODS"; break;
		case 11: str = "CURRENT TRENDS IRONWORKS"; break;
		case 12: str = "THE INN OF ERLIQUIN"; break;
		case 18: str = "TEMPLE GAUCHE"; break;
		case 20: str = "TAVERN OF TALL TALES"; break;
		case 21: str = "SUPERIOR TRAINING"; break;
		default: str = ""; break;
	}
    _pGameModel -> addMessage(str);
}

void Maze04::exitB1(){
    _pGameModel -> addMessage("Exit to B1");
    _pGameModel -> selectMap(19);
    _pGameModel -> setPosition(13, 1);
}

void Maze04::teleport(){
    _pGameModel -> addMessage("Teleport");
}

void Maze04::agar(){
    _pGameModel -> addMessage("TENACIOUS LEPRECHAUN");
}

void Maze04::downstairs(){
    _pGameModel -> addMessage("Downstairs");
    _pGameModel -> selectMap(8);
    _pGameModel -> setPosition(0,7);
}

void Maze04::treasure(){
    _pGameModel -> addMessage("Treasure");
}

 // to do encounter
void Maze04::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}

void Maze04::golem(){
    _pGameModel -> addMessage("Golem");
}

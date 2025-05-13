#include "maze01.h"
#include "../GameModel.h"


Maze01::Maze01(GameModel* gm){
	_ovrName = "Portsmith";
	_description = "Portsmith";
	_scriptsCount = 24;
    _pGameModel = gm;
}

void Maze01::launchScript(int posX, int posY, DIRECTION dir){

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
        case 0: inn(); break;
        case 1: zam(); break;
        case 2: blacksmith(); break;
        case 3: market(); break;
        case 4: exitB3(); break;
        case 5: tavern(); break;
        case 6: temple(); break;
        case 7: training(); break;
        case 8: succubus(); break;
        case 9: downstairs(); break;
        case 10: doorSign(scriptNumber); break;
        case 11: doorSign(scriptNumber); break;
        case 12: doorSign(scriptNumber); break;
        case 13: doorSign(scriptNumber); break; 
        case 14: doorSign(scriptNumber); break;
        case 15: doorSign(scriptNumber); break;
        case 16: doorSign(scriptNumber); break;
        case 17: 
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27: trap(); break;
        default: break;
    }

}

void Maze01::inn(){
    _pGameModel -> addMessage("INN");
}

void Maze01::blacksmith(){
    _pGameModel -> addMessage("BLACKSMITH");
}

void Maze01::market(){
    _pGameModel -> addMessage("MARKET");
}

void Maze01::tavern(){
    _pGameModel -> addMessage("TAVERN");
}

void Maze01::temple(){
    _pGameModel -> addMessage("TEMPLE");
}

void Maze01::training(){
    _pGameModel -> addMessage("TRAINING");
}

void Maze01::doorSign(int id){
	std::string str;
	switch (id){
		case 10: str = "MAID MARION'S MARKET"; break;
		case 11: str = "B. SMITH'S WORKSHOP"; break;
		case 12: str = "INN OF PORTSMITH"; break;
		case 13: str = "TEMPLE SUCCUBON"; break;
		case 15: str = "ZORELDA'S WATERING HOLE"; break;
		case 16: str = "AMAZONIA'S TRAINING"; break;
		case 14: str = "NOTE: ZAM 12,2"; break;
		default: str = ""; break;
	}
    _pGameModel -> addMessage(str);
}

void Maze01::exitB3(){
    _pGameModel -> addMessage("PASSAGE OUTSIDE, EXIT (Y/N)?");
    _pGameModel -> selectMap(20);
    _pGameModel -> setPosition(3,3);
}

void Maze01::zam(){
    _pGameModel -> addMessage("ZAM");
}

void Maze01::succubus(){
    _pGameModel -> addMessage("Succubus Queen");
}

void Maze01::downstairs(){
    _pGameModel -> addMessage("STAIRS GOING DOWN! TAKE THEM (Y/N)?");
    _pGameModel -> selectMap(7);
    _pGameModel -> setPosition(8, 0);
}



void Maze01::trap(){
    _pGameModel -> addMessage("Male trap");
}

 // to do encounter
void Maze01::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}

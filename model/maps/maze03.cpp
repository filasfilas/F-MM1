#include "maze03.h"
#include "../GameModel.h"


Maze03::Maze03(GameModel* gm){
	_ovrName = "Dusk";
	_description = "Dusk";
	_scriptsCount = 29;
    	_pGameModel = gm;
}

void Maze03::launchScript(int posX, int posY, DIRECTION dir){

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
        case 1: telgoran(); break;
        case 2: blacksmith(); break;
        case 3: market(); break;
        case 4: exitE1(); break;
        case 5: tavern(); break;
        case 6: temple(); break;
        case 7: training(); break;
        case 8: treasure(); break;
        case 9: downstairs(); break;
        case 10:
        case 11: 
        case 12: doorSign(scriptNumber); break;
        case 13: switch(0); break; 
        case 14: switch(1); break;
        case 15:
        case 16:
        case 17: localEncounter(scriptNumber); break;
        case 18: doorSign(scriptNumber); break;
        case 19: localEncounter(scriptNumber); break;
        case 20:
        case 21: doorSign(scriptNumber); break;
        case 22: 
        case 23: 
        case 24:
        case 25:
        case 26: localEncounter(scriptNumber); break;
        case 27:
        case 28: doorSign(scriptNumber); break;
        default: break;
    }

}

void Maze03::inn(){
    _pGameModel -> addMessage("INN");
}

void Maze03::blacksmith(){
    _pGameModel -> addMessage("BLACKSMITH");
}

void Maze03::market(){
    _pGameModel -> addMessage("MARKET");
}

void Maze03::tavern(){
    _pGameModel -> addMessage("TAVERN");
}

void Maze03::temple(){
    _pGameModel -> addMessage("TEMPLE");
}

void Maze03::training(){
    _pGameModel -> addMessage("TRAINING");
}

void Maze03::doorSign(int id){
	std::string str;
	switch (id){
		case 10: str = "FEWLERD'S FEED"; break;
		case 11: str = "MYSTICAL METAL WORKS"; break;
		case 12: str = "THE INN OF DUSK"; break;
		case 18: str = "TEMPLE GEIST"; break;
		case 20: str = "CASPER'S FINE SPIRITS"; break;
		case 21: str = "CLEARMAN'S TRAINING"; break;
		case 27: str = "FORBIDDEN CRYPT"; break;
		case 28: str = "ETERNAL REST CHAMBER"; break;
		default: str = ""; break;
	}
    _pGameModel -> addMessage(str);
}

void Maze03::exitE1(){
    _pGameModel -> addMessage("Exit to E1");
    _pGameModel -> selectMap(30);
    _pGameModel -> setPosition(9, 11);
}

void Maze03::lever(int id){
    _pGameModel -> addMessage("Switch");
/*
    if (id==0) {
	MAP_29=  80;
	MAP_46 = 3;
	MAP_47 = 3;
    }else{
	MAP_29=  150;
	MAP_46 = 2;
	MAP_47 = 2;
    }
*/
}

void Maze03::telgoran(){
    _pGameModel -> addMessage("TENACIOUS LEPRECHAUN");
}

void Maze03::downstairs(){
    _pGameModel -> addMessage("Downstairs");
    _pGameModel -> selectMap(9);
    _pGameModel -> setPosition(14, 0);
}

void Maze03::treasure(){
    _pGameModel -> addMessage("Treasure");
}

 // to do encounter
void Maze03::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}

void Maze03::localEncounter(int scriptNumber){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}

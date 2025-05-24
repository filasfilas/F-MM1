#include "maze20.h"
#include "../GameModel.h"


Maze20::Maze20(GameModel* gm){
	_ovrName = "areaB3";
	_description = "areaB3";
	_scriptsCount = 9;
   	_pGameModel = gm;

    _localFlag = false;
}

void Maze20::launchScript(int posX, int posY, DIRECTION dir){

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
        case 0: enterPortsmith(); break;
        case 1: enterCavesKorin(); break;
        case 2: enterCastleWhiteWolf(); break;
        case 3: enterStronghEf1(); break;
        case 4: sign("A SIGN POINTING N. READS: WHITE WOLF"); break;
        case 5: sign("A SIGN POINTING S. READS: PORTSMITH"); break; 
        case 6: blithesPeak(); break; 
        case 7: 
        case 8: teleport(); break;
        default: break;
    }

}

void Maze20::enterPortsmith(){
    _pGameModel -> addMessage("PASSAGE TO PORTSMITH, TAKE IT (Y/N)?");
    _pGameModel -> selectMap(1);
    _pGameModel -> setPosition(1, 15);
}

void Maze20::enterCavesKorin(){
    _pGameModel -> addMessage("A CAVE, ENTER (Y/N)?");
    _pGameModel -> selectMap(10);
    _pGameModel -> setPosition(15, 0);
}

void Maze20::enterCastleWhiteWolf(){
    _pGameModel -> addMessage("CASTLE WHITE WOLF, ENTER (Y/N)?");
    _pGameModel -> selectMap(43);
    _pGameModel -> setPosition(15, 8);
}

void Maze20::enterStronghEf1(){
    _pGameModel -> addMessage("AN ANCIENT TEMPLE CONVERTED TO A STRONGHOLD HAS NO APPARENT ENTRANCE.");
    _pGameModel -> selectMap(41);
    _pGameModel -> setPosition(8, 5);
}


void Maze20::blithesPeak(){
    _pGameModel -> addMessage("ATOP THIS PEAK LOOKING:");
}

void Maze20::teleport(){
    _pGameModel -> addMessage("POOF");
    _pGameModel -> setPosition(9, 6);
}


void Maze20::sign(std::string str){
    _pGameModel -> addMessage(str);
}


 // to do encounter
void Maze20::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}

void Maze20::localAction(int posX, int posY){
	if ((posY>10)||(posX>11)){encounter();}
/*
	else if((posY==9)&&(posX<2)){encounter();}
	else if((posY<4)&&(posX==11)){encounter();}
	else if((posY==8)&&(posX==8)){encounter();}
	else if((posY==6)&&(posX==7)){encounter();}
*/
	else {_pGameModel -> addMessage("sea");}
}


#include "maze18.h"
#include "../GameModel.h"


Maze18::Maze18(GameModel* gm){
	_ovrName = "areaB1";
	_description = "areaB1";
	_scriptsCount = 10;
   	_pGameModel = gm;

    _localFlag = false;
}

void Maze18::launchScript(int posX, int posY, DIRECTION dir){

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
        case 0: enterErliquin(); break;
        case 1: enterCastleBlS(); break;
        case 2: enterCastleBlN(); break;
        case 3: enterWizardLair(); break;
        case 4: sign("A SIGN POINTING S. READS: BLACKRIDGE N."); break;
        case 5: sign("A SIGN POINTING E. READS: BLACKRIDGE S."); break; 
        case 6: sign("A SIGN POINTING E. READS: ERLIQUIN"); break; 
        case 7: gateMM2(); break;
        case 8: enterErliquinDang(); break;
        case 9: silverKey(); break;
        default: break;
    }

}

void Maze18::enterErliquin(){
    _pGameModel -> addMessage("CAVERNOUS PASSAGE TO ERLIQUIN, TAKE IT (Y/N)?");
    _pGameModel -> selectMap(4);
    _pGameModel -> setPosition(0, 7);
}

void Maze18::enterCastleBlS(){
    _pGameModel -> addMessage("CASTLE BLACKRIDGE SOUTH, ENTER (Y/N)?");
    _pGameModel -> selectMap(36);
    _pGameModel -> setPosition(0, 7);
}

void Maze18::enterCastleBlN(){
    _pGameModel -> addMessage("CASTLE BLACKRIDGE NORTH, ENTER (Y/N)?");
    _pGameModel -> selectMap(35);
    _pGameModel -> setPosition(7, 15);
}

void Maze18::enterWizardLair(){
    _pGameModel -> addMessage("ANCIENT RUINS OF A DESERTED WIZARDS LAIRSHOW SIGNS OF RECENT USE, ENTER (Y/N)?");
    _pGameModel -> selectMap(37);
    _pGameModel -> setPosition(2, 2);
}

void Maze18::enterErliquinDang(){
    _pGameModel -> addMessage("A CAVE, ENTER (Y/N)?");
    _pGameModel -> selectMap(8);
    _pGameModel -> setPosition(15, 7);
}

void Maze18::gateMM2(){
    _pGameModel -> addMessage("gateMM2");
}

void Maze18::silverKey(){
    _pGameModel -> addMessage("silverKey");
}


void Maze18::sign(std::string str){
    _pGameModel -> addMessage(str);
}


 // to do encounter
void Maze18::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}



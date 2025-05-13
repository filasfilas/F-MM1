#include "maze02.h"
#include "../GameModel.h"


Maze02::Maze02(GameModel* gm){
	_ovrName = "Algary";
	_description = "Algary";
	_scriptsCount = 24;
    	_pGameModel = gm;
}

void Maze02::launchScript(int posX, int posY, DIRECTION dir){

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
        case 1: zom(); break;
        case 2: blacksmith(); break;
        case 3: market(); break;
        case 4: exitD4(); break;
        case 5: tavern(); break;
        case 6: temple(); break;
        case 7: training(); break;
        case 8: morango(); break;
        case 9:
        case 10:
        case 11: 
        case 12: doorSign(scriptNumber); break;
        case 13: sign("Zom"); break;
        case 14: pit(); break;
        case 15: teleport(18); break;	//teleport to B1
        case 16: teleport(50); break;	//Fabled building of Gold lvl1
        case 17: teleport(0); break;	//teleport to Sorpigal
        case 18: doorSign(scriptNumber); break;
        case 19: teleport(1); break;	//teleport to Portsmith
        case 20: 
        case 21: doorSign(scriptNumber); break;
        default: break;
    }

}

void Maze02::inn(){
    _pGameModel -> addMessage("INN");
}

void Maze02::blacksmith(){
    _pGameModel -> addMessage("BLACKSMITH");
}

void Maze02::market(){
    _pGameModel -> addMessage("MARKET");
}

void Maze02::tavern(){
    _pGameModel -> addMessage("TAVERN");
}

void Maze02::temple(){
    _pGameModel -> addMessage("TEMPLE");
}

void Maze02::training(){
    _pGameModel -> addMessage("TRAINING");
}

void Maze02::doorSign(int id){
	std::string str;
	switch (id){
		case 9: str = "YE OLD DOCKS"; break;
		case 10: str = "ARCON'S SLOP"; break;
		case 11: str = "SWAMPSIDE SUPPLIES"; break;
		case 12: str = "THE INN OF ALGARY"; break;
		case 18: str = "TEMPLE HALF-DEAD"; break;
		case 20: str = "JOLLY JESTER TAVERN"; break;
		case 21: str = "DRAGONS CLAW TRAINING"; break;
		default: str = ""; break;
	}
    _pGameModel -> addMessage(str);
}

void Maze02::sign(std::string str){
    _pGameModel -> addMessage(str);
}

void Maze02::exitD4(){
    _pGameModel -> addMessage("Exit to D4");
    _pGameModel -> selectMap(29);
    _pGameModel -> setPosition(7,7);
}

void Maze02::zom(){
    _pGameModel -> addMessage("Zom");
}

void Maze02::morango(){
    _pGameModel -> addMessage("Morango");
}

void Maze02::pit(){
    _pGameModel -> addMessage("Pit");
}

void Maze02::teleport(int id){
    _pGameModel -> addMessage("A MAGIC PORTAL! ENTER (Y/N)?");
   
    switch(id){
	case 1: _pGameModel -> setPosition(8,4); break;
	case 18: _pGameModel -> setPosition(15,0); break;
	case 50: _pGameModel -> setPosition(0,0); break;
	case 0: _pGameModel -> setPosition(5,14); break;
    }
    _pGameModel -> selectMap(id);
}


 // to do encounter
void Maze02::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}

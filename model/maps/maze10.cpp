#include "maze10.h"
#include "../GameModel.h"

int newX[15] = {7, 7, 3, 3, 7, 13, 1, 7, 9, 13, 12, 1, 8, 12, 4};
int newY[15] = {3, 14, 7, 7, 12, 8, 13, 3, 0, 7, 2, 14, 13, 7, 7};
int newMap[15] = {34, 44, 49, 35, 36, 43, 5, 6, 7, 8, 0, 1, 2, 3, 4};

Maze10::Maze10(GameModel* gm){
	_ovrName = "cave6";
	_description = "The Caves at the Korin Bluffs";
	_scriptsCount = 34;
   	_pGameModel = gm;
}

void Maze10::launchScript(int posX, int posY, DIRECTION dir){

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
        case 0: exitB3(); break;
        case 1: wizardRanalou(); break;
        case 2: 
        case 3: 
        case 4: 
        case 5: 
        case 6: 
        case 7:  
        case 8: 
        case 9:   
        case 10: 
        case 11:
        case 12: 
        case 13:  
        case 14: 
        case 15: 
        case 16: teleport(scriptNumber-2); break;
        case 17: localTeleport(13, 7); break; 
        case 18: localTeleport(8, 0); break;
        case 19: localTeleport(5, 2); break;
        case 20:
        case 21:
        case 22: thundranium(); break;
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28: trap(); break;
        case 29: sign("A SIGN"); break;
        case 30: thundranium(); break;
        case 31: sign("A SIGN"); break;
        case 32: aliens(); break;
        case 33: localTeleport(15, 4); break;
        default: break;
    }

}

void Maze10::exitB3(){
    _pGameModel -> addMessage("A PASSAGE LEADS OUTSIDE, TAKE IT (Y/N)?");
    _pGameModel -> selectMap(20);
    _pGameModel -> setPosition(0, 7);
}

void Maze10::wizardRanalou(){
    _pGameModel -> addMessage("I'M THE WIZARD RANALOU. ARE YOU HERE TOUSE THE PORTALS (Y/N)?");
}

void Maze10::teleport(int id){
    _pGameModel -> addMessage("POOF! YOU'VE BEEN TELEPORTED");
    _pGameModel -> selectMap(newMap[id]);
    _pGameModel -> setPosition(newX[id], newY[id]);
}

void Maze10::localTeleport(int posX, int posY){
    _pGameModel -> setPosition(posX, posY);
}

void Maze10::thundranium(){
    _pGameModel -> addMessage("Thundranium");
}

void Maze10::trap(){
    _pGameModel -> addMessage("JAGGED SLIME PIT!");
}

void Maze10::aliens(){
    _pGameModel -> addMessage("aliens"); 
}

void Maze10::sign(std::string str){
    _pGameModel -> addMessage(str);
}


 // to do encounter
void Maze10::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}


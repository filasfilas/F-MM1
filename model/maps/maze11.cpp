#include "maze11.h"
#include "../GameModel.h"


Maze11::Maze11(GameModel* gm){
	_ovrName = "cave7";
	_description = "The Volcano";
	_scriptsCount = 14;
   	_pGameModel = gm;
}

void Maze11::launchScript(int posX, int posY, DIRECTION dir){

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
	    case -1: localAction(); break;
        case 0: exitC4(); break;
        case 1: volcanoGod(); break;
        case 2: lavaPit(); break; 
        case 3: sign("PAINTED IN A BLACK AND WHITE ..."); break;
        case 4: virgin(); break;
        case 5: sign("THIS CAVERN IS RANDOM UNTIL THE DIALS ARE SET."); break; 
        case 6: stabilizer(); break;
        case 7: stabilizer(); break;
        case 8: 
        case 9:   
        case 10: encounter(); break;
        case 11:
        case 12: 
        case 13: lavaPit(); break;  
        default: break;
    }

}

void Maze11::exitC4(){
    _pGameModel -> addMessage("A LADDER GOING UP, TAKE IT (Y/N)?");
    _pGameModel -> selectMap(25);
    _pGameModel -> setPosition(7, 2);
}

void Maze11::volcanoGod(){
    _pGameModel -> addMessage("THE VOLCANO GOD BELLOWS.");
}

void Maze11::lavaPit(){
    _pGameModel -> addMessage("PIT OF BUBBLING LAVA!");
}

void Maze11::virgin(){
    _pGameModel -> addMessage("A LUSCIOUS VIRGIN SHACKLED TO THE WALL!  A) KISS HER  B) RELEASE HER  C) LEAVE");
}

void Maze11::stabilizer(){
    _pGameModel -> addMessage("STABILIZATION DIAL #  SET (A-Z)?");
}


void Maze11::sign(std::string str){
    _pGameModel -> addMessage(str);
}


void Maze11::localAction(){
    _pGameModel -> addMessage("action");
}

 // to do encounter
void Maze11::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}


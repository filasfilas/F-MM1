#include "maze12.h"
#include "../GameModel.h"


Maze12::Maze12(GameModel* gm){
	_ovrName = "cave8";
	_description = "The Magic Square";
	_scriptsCount = 18;
   	_pGameModel = gm;
}

void Maze12::launchScript(int posX, int posY, DIRECTION dir){

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
        case 0: exitD3(); break;
        case 1: platinumLever(); break;
        case 2: sign("A GLOWING POLYHEDRON IS SET ON SIDE"); break;
        case 3: sign("A GLOWING POLYHEDRON IS SET ON SIDE"); break;
        case 4: sign("A GLOWING POLYHEDRON IS SET ON SIDE"); break;
        case 5: sign("A GLOWING POLYHEDRON IS SET ON SIDE"); break;
        case 6: sign("A GLOWING POLYHEDRON IS SET ON SIDE"); break;
        case 7: sign("A GLOWING POLYHEDRON IS SET ON SIDE"); break;
        case 8: sign("A GLOWING POLYHEDRON IS SET ON SIDE"); break;
        case 9:
        case 10:
        case 11:
        case 12: 
        case 13:
        case 14:
        case 15:
        case 16:
        case 17: spinner(); break;
        default: break;
    }

}

void Maze12::exitD3(){
    _pGameModel -> addMessage("LADDER UP, CLIMB (Y/N)?");
    _pGameModel -> selectMap(28);
    _pGameModel -> setPosition(7, 13);
}

void Maze12::platinumLever(){
    _pGameModel -> addMessage("PLATINUM LEVER PROTRUDES FROM THE WALL.");
}

void Maze12::spinner(){
    _pGameModel -> addMessage("THE POLYHEDRON IS SET ON SPIN IT (Y/N)?");
}


void Maze12::sign(std::string str){
    _pGameModel -> addMessage(str);
}


 // to do encounter
void Maze12::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}


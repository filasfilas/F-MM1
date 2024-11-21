#include "maze23.h"
#include "../GameModel.h"

Maze23::Maze23(GameModel* gm){
	_ovrName = "areaC2";
	_description = "area C2";
	_scriptsCount = 14;
    _pGameModel = gm;

}

void Maze23::launchScript(int posX, int posY, DIRECTION dir){
	//search for script number
	int position = posX + 16*posY;
	int scriptNumber = -1;
	for (int i =0; i< _scriptsCount; i++){
		if (position == _scriptXY[i]){
			if (dir & _scriptDirection[i]) {
				scriptNumber = i;
			}
		}
	}
    switch (scriptNumber){
        case 0: entranceSorpigal(); break;
        case 1: entranceCrazeWizardCave(); break;
        case 2: gypsy(); break;
        case 3: 
        case 4:
        case 5:
        case 6:
        case 7: pit(); break;
        case 8: teleport(); break;
        case 9: statue(); break;
        case 10:
        case 11: fountain(); break;
        case 12: avalanche(); break;
        case 13: chest(); break;
        default: encounter(); break;
    }

}


void Maze23::entranceSorpigal(){
    _pGameModel -> addMessage("SORPIGAL");
}

void Maze23::gypsy(){
    _pGameModel -> addMessage("gipsy");
}

void Maze23::pit(){
    _pGameModel -> addMessage("pit");
}

void Maze23::teleport(){
    _pGameModel -> addMessage("teleport");
}

void Maze23::statue(){
    _pGameModel -> addMessage("Statue");
}

void Maze23::fountain(){
    _pGameModel -> addMessage("fountain");
}

void Maze23::avalanche(){
    _pGameModel -> addMessage("avalanche");
}

void Maze23::entranceCrazeWizardCave(){
    _pGameModel -> addMessage("CrazeWizardCave");
}

void Maze23::chest(){
    _pGameModel -> addMessage("chest");
}

 // to do encounter
void Maze23::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}

#include "maze23.h"


Maze23::Maze23(){
	_ovrName = "areaC2";
	_description = "area C2";
	_scriptsCount = 14;

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
        default: break; // to do encounter
    }

}


void Maze23::entranceSorpigal(){
}

void Maze23::gypsy(){
}

void Maze23::pit(){
}

void Maze23::teleport(){
}

void Maze23::statue(){
}

void Maze23::fountain(){
}

void Maze23::avalanche(){
}

void Maze23::entranceCrazeWizardCave(){
}

void Maze23::chest(){
}

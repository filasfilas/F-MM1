#include "maze13.h"
#include "../GameModel.h"


Maze13::Maze13(GameModel* gm){
	_ovrName = "cave9";
	_description = "The Medusa Lair";
	_scriptsCount = 23;
   	_pGameModel = gm;
}

void Maze13::launchScript(int posX, int posY, DIRECTION dir){

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
        case 0: exitB2(); break;
        case 1: medusas(); break;
        case 2: 
        case 3: 
        case 4: 
        case 5: poisonSpikes(); break;
        case 6: 
        case 7:
        case 8:
        case 9: sign("SMASHED REMAINS OF STONE STATUES SEEM SUSPICIOUSLY LIFELIKE."); break;  
        case 10:
        case 11:
        case 12: 
        case 13:  
        case 14: 
        case 15: 
        case 16: 
        case 17: snakePit(); break; 
        case 18: 
        case 19: 
        case 20: 
        case 21: 
        case 22: localEncounter(); break;
        default: break;
    }

}

void Maze13::exitB2(){
    _pGameModel -> addMessage("A PASSAGE LEADS OUTDOORS, EXIT (Y/N)?");
    _pGameModel -> selectMap(19);
    _pGameModel -> setPosition(8, 4);
}

void Maze13::medusas(){
    _pGameModel -> addMessage("medusas");
}

void Maze13::poisonSpikes(){
    _pGameModel -> addMessage("A TRAP! A PIT FULL OF POISONOUS SPIKES OPENS BELOW THE PARTY!");
}

void Maze13::snakePit(){
    _pGameModel -> addMessage("SNAKE PIT!");
}


void Maze13::sign(std::string str){
    _pGameModel -> addMessage(str);
}


void Maze13::localEncounter(){
    _pGameModel -> addMessage("Encounter");
}

 // to do encounter
void Maze13::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}


#include "maze05.h"
#include "../GameModel.h"


Maze05::Maze05(GameModel* gm){
	_ovrName = "cave1";
	_description = "Sorpigal Dungeon";
	_scriptsCount = 21;
    	_pGameModel = gm;
}

void Maze05::launchScript(int posX, int posY, DIRECTION dir){

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
        case 0: exitSorpigal(); break;
        case 1: localEncounter(1); break;
        case 2: localEncounter(9); break;
        case 3: localEncounter(0xd); break;
        case 4: localEncounter(20); break;
        case 5: localEncounter(0); break;
        case 6: elderlyMan(); break;
        case 7: portal(); break;  //portal to Crazed Wizard Cave
        case 8: sign("ARENA"); break;
        case 9: arena(); break;
        case 10: sign("THE JAIL ABOVE HAS MANY CELLS."); break;
        case 11: 
        case 12: 
        case 13: signTrap(posX, dir); break;
        case 14: localEncounter(0); break;
        case 15: localEncounter(0); break;
        case 16: localEncounter(0); break;
        case 17: localEncounter(0); break;
        case 18: localEncounter(0); break;
        case 19: localEncounter(0); break;
        case 20: sign("ARENA"); break;
        default: break;
    }

}

void Maze05::exitSorpigal(){
    _pGameModel -> addMessage("Exit to Sorpigal");
    _pGameModel -> selectMap(0);
    _pGameModel -> setPosition(14, 0);
}

void Maze05::elderlyMan(){
    _pGameModel -> addMessage("Elderly Man");
}

void Maze05::portal(){
    _pGameModel -> addMessage("portal to the Crazed WIzard Cave");
}

void Maze05::sign(std::string str){
    _pGameModel -> addMessage(str);
}

void Maze05::signTrap(int posX, DIRECTION dir){
    if (dir == 0xc0){
   	 _pGameModel -> addMessage("Don't turn around!");
   }else{
	//clean special
   	 _pGameModel -> addMessage("Encounter!");
   }
}

void Maze05::arena(){
    _pGameModel -> addMessage("ARENA");
}

 // to do encounter
void Maze05::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}

void Maze05::localEncounter(int num){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}

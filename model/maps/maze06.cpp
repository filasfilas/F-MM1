#include "maze06.h"
#include "../GameModel.h"


Maze06::Maze06(GameModel* gm){
	_ovrName = "cave2";
	_description = "The Crazed Wizard Cave";
	_scriptsCount = 27;
    	_pGameModel = gm;

	_sliderFlag = true;
}

void Maze06::launchScript(int posX, int posY, DIRECTION dir){

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
	case -1: slider(posX, posY); break;
        case 0: exitC2(); break;
        case 1: exitPortsmDang(); break;
        case 2: slide(2); break;
        case 3: slide(3); break;
        case 4: 
        case 5: acidPool(); break;
        case 6: slideButton(); break;
        case 7:  
        case 8: teleport(); break; 
        case 9: sign("A BANNER READS: CORRIDOR OF ENDLESS ENCOUNTERS!"); break;
        case 10: 
        case 11: 
        case 12: endlessEncounter(posX); break;
        case 13: localEncounter(0); break;
        case 14: localEncounter(0); break;
        case 15: localEncounter(0); break;
        case 16: localEncounter(0); break;
        case 17: localEncounter(0); break;
        case 18: localEncounter(0); break;
        case 19: localEncounter(0); break;
        case 20: localEncounter(0); break;
        case 21: localEncounter(0); break;
        case 22: localEncounter(0); break;
        case 23: localEncounter(0); break;
        case 24: localEncounter(0); break;
        case 25: localEncounter(0); break;
        case 26: crazedWizard(); break;
        default: break;
    }

}

void Maze06::exitC2(){
    _pGameModel -> addMessage("PASSAGE OUTSIDE, EXIT (Y/N)?");
    _pGameModel -> selectMap(23);
    _pGameModel -> setPosition(15, 11);
}

void Maze06::exitPortsmDang(){
    _pGameModel -> addMessage("SHIMMERING BLUE AND WHITE PORTAL, ENTER (Y/N)?");
    _pGameModel -> selectMap(7);
    _pGameModel -> setPosition(7, 0);
}

void Maze06::crazedWizard(){
    _pGameModel -> addMessage("Crazed Wizard");
}

void Maze06::teleport(){
    _pGameModel -> addMessage("POOF");
    _pGameModel -> setPosition(10, 11);
}

void Maze06::sign(std::string str){
    _pGameModel -> addMessage(str);
}

void Maze06::acidPool(){
    _pGameModel -> addMessage("Acid Pool");
}

void Maze06::slideButton(){
    _pGameModel -> addMessage("BUTTON ON THE WALL, PRESS IT (Y/N)?");
    _sliderFlag = !_sliderFlag;
}

 // to do encounter
void Maze06::endlessEncounter(int posX){
    _pGameModel -> setPosition(posX+1, 15);
    _pGameModel -> addMessage("ENCOUNTER !!!");
}

void Maze06::localEncounter(int num){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}

void Maze06::slider(int posX, int posY){
    if (!_sliderFlag) return;
    _pGameModel -> addMessage("Slider !!!");
}

void Maze06::slide(int id){
    if (!_sliderFlag) return;
    _pGameModel -> addMessage("Slider !!!");
}

#include "maze15.h"
#include "../GameModel.h"


Maze15::Maze15(GameModel* gm){
	_ovrName = "areaA2";
	_description = "areaA2";
	_scriptsCount = 9;
   	_pGameModel = gm;

    _dragonFlag = false;
}

void Maze15::launchScript(int posX, int posY, DIRECTION dir){

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
	    case -1: localAction(posX, posY); break;
        case 0: sign("LAVA FILLS THE VALLEY OF FIRE!"); break;
        case 1: redDragon(); break;
        case 2: 
        case 3: encounter(); break; 
        case 4: pirateSecretB(); break;
        case 5: pirateSecretA(); break;
        case 6: druid(); break;
        case 7: sign("LAVA FILLS THE VALLEY OF FIRE!"); break;
        case 8: resetFlag(); break;
        default: break;
    }

}

void Maze15::redDragon(){
    _dragonFlag = true;
    _pGameModel -> addMessage("red dragon");
}

void Maze15::pirateSecretA(){
    _pGameModel -> addMessage("A PIRATES SECRET COVE, SEARCH (Y/N)?");
}

void Maze15::pirateSecretB(){
    _pGameModel -> addMessage("A PIRATES SECRET COVE, SEARCH (Y/N)?");
}

void Maze15::druid(){
    _pGameModel -> addMessage("I AM PERCELLA THE DRUID");
}

void Maze15::resetFlag(){
    _dragonFlag = false;
    _pGameModel -> addMessage("resetFlag");
}

void Maze15::sign(std::string str){
    _pGameModel -> addMessage(str);
}


 // to do encounter
void Maze15::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}

void Maze15::localAction(int posX, int posY){
    if(posY<3){
        sea();
    }
    if(posY>6){
        lava();
        return;
    }
}

void Maze15::sea(){
    _pGameModel -> addMessage("sea");
}

void Maze15::lava(){
    _pGameModel -> addMessage("IT'S HOT!");
}

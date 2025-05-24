#include "maze21.h"
#include "../GameModel.h"


Maze21::Maze21(GameModel* gm){
	_ovrName = "areaB4";
	_description = "areaB4";
	_scriptsCount = 8;
   	_pGameModel = gm;

    _localFlag = false;
}

void Maze21::launchScript(int posX, int posY, DIRECTION dir){

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
        case 0: ghostShip(); break;
        case 1: triviaChance(); break;
        case 2: triviaIsland(); break;
        case 3: puzzle(1); break;
        case 4: puzzle(2); break;
        case 5: puzzle(3); break; 
        case 6: puzzle(4); break;
        case 7: puzzle(5); break;
        default: break;
    }

}

void Maze21::ghostShip(){
    _pGameModel -> addMessage("PIRATE GHOSTSHIP ANARCHIST!");
}

void Maze21::triviaChance(){
	_localFlag = true;
    _pGameModel -> addMessage("FREE TRIVIA CHANCE, PULL BRANCH (Y/N)?");
}

void Maze21::triviaIsland(){
    _pGameModel -> addMessage("TRIVIA ISLAND! 500 GOLD, ENTER (Y/N)?");

}

void Maze21::puzzle(int id){
    _pGameModel -> addMessage("puzzle");
}


void Maze21::sign(std::string str){
    _pGameModel -> addMessage(str);
}


 // to do encounter
void Maze21::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}

void Maze21::localAction(int posX, int posY){
	if ((posY>12)&&(posX>11)){encounter();}
/*
	else if((posY==14)&&(posX==0)){encounter();}
	else if((posY==9)&&(posX==2)){encounter();}
	else if((posY==3)&&(posX==2)){encounter();}
	else if((posY==0)&&(posX==4)){encounter();}
	else if((posY==11)&&(posX==4)){encounter();}
	else if((posY==2)&&(posX==6)){encounter();}
	else if((posY==9)&&(posX==6)){encounter();}
	else if((posY==13)&&(posX==6)){encounter();}
	else if((posY==3)&&(posX==7)){encounter();}
	else if((posY==3)&&(posX==9)){encounter();}
	else if((posY==2)&&(posX==10)){encounter();}
	else if((posY==1)&&(posX==11)){encounter();}
	else if((posY==8)&&(posX==12)){encounter();}
	else if((posY==0)&&(posX==13)){encounter();}
*/
	else {_pGameModel -> addMessage("sea");}
}


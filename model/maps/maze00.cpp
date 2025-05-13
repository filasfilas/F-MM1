#include "maze00.h"
#include "../GameModel.h"


Maze00::Maze00(GameModel* gm){
	_ovrName = "Sorpigal";
	_description = "Sorpigal";
	_scriptsCount = 24;
    _pGameModel = gm;
}

void Maze00::launchScript(int posX, int posY, DIRECTION dir){

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
        case 0: inn(); break;
        case 1: doorSign(scriptNumber + dir); break;
        case 2: blacksmith(); break;
        case 3: market(); break;
        case 4: exitC2(); break;
        case 5: tavern(); break;
        case 6: temple(); break;
        case 7: training(); break;
        case 8: leprechaun(); break;
        case 9: downstairs(); break;
        case 10:
        case 11: 
        case 12: 
        case 13: 
        case 14:
        case 15:
        case 16:
        case 17: statue(scriptNumber-10); break;
        case 18:
        case 19:
        case 20:
        case 21: doorSign(scriptNumber); break;
        case 22: changeMonsterLevel(); break;
        case 23: hole(); break;
        default: break;
    }

}

void Maze00::inn(){
    _pGameModel -> addMessage("INN");
}

void Maze00::blacksmith(){
    _pGameModel -> addMessage("BLACKSMITH");
}

void Maze00::market(){
    _pGameModel -> addMessage("MARKET");
}

void Maze00::tavern(){
    _pGameModel -> addMessage("TAVERN");
}

void Maze00::temple(){
    _pGameModel -> addMessage("TEMPLE");
}

void Maze00::training(){
    _pGameModel -> addMessage("TRAINING");
}

void Maze00::doorSign(int id){
	std::string str;
	switch (id){
		case 49: str = "EULARDS FINE FOODS"; break;
		case 4: str = "B AND B BLACKSMITHS"; break;
		case 13: str = "THE INN OF SORPIGAL"; break;
		case 18: str = "TEMPLE MOONSHADOW"; break;
		case 19: str = "JAIL, KEEP OUT!"; break;
		case 20: str = "YE OLDE HOGGE TAVERN"; break;
		case 21: str = "OTTO'S TRAINING"; break;
		default: str = ""; break;
	}
    _pGameModel -> addMessage(str);
}

void Maze00::exitC2(){
    _pGameModel -> addMessage("Exit to C2");
    _pGameModel -> selectMap(23);
    _pGameModel -> setPosition(10, 10);
}

void Maze00::leprechaun(){
    _pGameModel -> addMessage("TENACIOUS LEPRECHAUN");
}

void Maze00::downstairs(){
    _pGameModel -> addMessage("Downstairs");
    _pGameModel -> selectMap(5);
    _pGameModel -> setPosition(14, 0);
}

void Maze00::statue(int statueNum){
	std::string str = "STATUE N" + statueNum;
    _pGameModel -> addMessage(str);
}

void Maze00::changeMonsterLevel(){
    _pGameModel -> addMessage("changeMonsterLevel");
}

void Maze00::hole(){
    _pGameModel -> addMessage("TRAP HOLE");
}

 // to do encounter
void Maze00::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}

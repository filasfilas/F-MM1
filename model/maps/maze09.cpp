#include "maze09.h"
#include "../GameModel.h"


Maze09::Maze09(GameModel* gm){
	_ovrName = "cave5";
	_description = "Dusk Dungeon";
	_scriptsCount = 28;
   	_pGameModel = gm;
}

void Maze09::launchScript(int posX, int posY, DIRECTION dir){

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
        case 0: exitDusk(); break;
        case 1: exitDragadune2(); break;
        case 2: portalSorpigal(); break;
        case 3: portalKorinBuff(); break;
        case 4: portalMagicSquare(); break;
        case 5: portalMedusaLair(); break;
        case 6: accuracy(); break;
        case 7: speed(); break; 
        case 8: shrineOkzar(); break;
        case 9:   
        case 10: 
        case 11:
        case 12: 
        case 13: stalactite(); break; 
        case 14: 
        case 15: 
        case 16: 
        case 17: poisonPit(); break;
        case 18:
        case 19:  
        case 20:
        case 21:
        case 22:
        case 23:
        case 24: physicalBlast(); break;
        case 25: sign("SCRAWLED IN STONE..."); break;
        case 26: sign("CORAK WAS HERE"); break;
        case 27: sign("BEHIND AN OLD TAPESTRY, A MESSAGE ETCHED IN GOLD READS: YICU2ME3"); break;
        default: break;
    }

}

void Maze09::exitDusk(){
    _pGameModel -> addMessage("STAIRS GOING UP! TAKE THEM (Y/N)?");
    _pGameModel -> selectMap(3);
    _pGameModel -> setPosition(14, 0);
}

void Maze09::exitDragadune2(){
    _pGameModel -> addMessage("A CAVERNOUS PASSAGE, TAKE IT (Y/N)?");
    _pGameModel -> selectMap(45);
    _pGameModel -> setPosition(0, 0);
}

void Maze09::portalSorpigal(){
    _pGameModel -> addMessage("BLUE AND WHITE PORTAL, ENTER (Y/N)?");
    _pGameModel -> selectMap(0);
    _pGameModel -> setPosition(8, 4);
}

void Maze09::portalKorinBuff(){
    _pGameModel -> addMessage("BLUE AND WHITE PORTAL, ENTER (Y/N)?");
    _pGameModel -> selectMap(10);
    _pGameModel -> setPosition(15, 5);
}

void Maze09::portalMagicSquare(){
    _pGameModel -> addMessage("BLUE AND WHITE PORTAL, ENTER (Y/N)?");
    _pGameModel -> selectMap(12);
    _pGameModel -> setPosition(15, 0);   
}

void Maze09::portalMedusaLair(){
    _pGameModel -> addMessage("BLUE AND WHITE PORTAL, ENTER (Y/N)?");
    _pGameModel -> selectMap(13);
    _pGameModel -> setPosition(7, 0);    
}

void Maze09::accuracy(){
    _pGameModel -> addMessage("THE PRISM OF PRECISION GRANTS THOSE WHO ARE WORTHY +4 ACCURACY!"); 
}

void Maze09::speed(){
    _pGameModel -> addMessage("THE FLAME OF AGILITY GRANTS THOSE WHO ARE WORTHY +4 SPEED!");  
}

void Maze09::shrineOkzar(){
    _pGameModel -> addMessage("THE SHRINE OF OKZAR, PRAY (Y/N)?"); 
}

void Maze09::stalactite(){
    _pGameModel -> addMessage("STALACTITES SHOWER THE PARTY!");   
}

void Maze09::poisonPit(){
    _pGameModel -> addMessage("A PIT OF POISONOUS SPIKES!");
}

void Maze09::physicalBlast(){
    _pGameModel -> addMessage("PSYCHIC BLAST!");
}

void Maze09::sign(std::string str){
    _pGameModel -> addMessage(str);
}


 // to do encounter
void Maze09::encounter(){
    _pGameModel -> addMessage("ENCOUNTER !!!");
}


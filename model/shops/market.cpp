#include "market.h"

//#include <fstream>
//#include <iostream>

Market::Market(GameModel* pGM)
:_pGameModel (pGM)
{}

int Market::getFoodCost(){
    int townNum = _pGameModel -> getMapId();
    if ((townNum<0)||(townNum>4)) return 999999;
	return _FOOD_COST[townNum];
}


void Market::buyFood(){
    int townNum = _pGameModel -> getMapId();
    int foodCost = getFoodCost();
}

#pragma once

#include <string>
#include <functional>


class GameModel;


class Market
{
	public:
		Market(GameModel* pGM);

        int getFoodCost();
        void buyFood();

	private:
        GameModel*  _pGameModel;
        const int FOOD_COST[5]={5, 10, 20, 200, 50};

};

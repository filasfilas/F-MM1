#include "Market.h"
//#include "CharacterDetailState.h"
#include "../../model/character.h"
//#include "../gui/Utility.h"
//#include <iostream>

MarketState ::MarketState (GlobalDataRef gData) 
: gData(gData)
{

}

void MarketState ::init() {

}

void MarketState ::handleInput(const sf::Event& event)
{

}

void MarketState::update (float dt){

}

void MarketState ::draw(float dt) {

	//temporary display clean. To delete when the state will be implemented.
	gData -> mWindow.clear(); //TO BE DELETED
/*
	for (int i=0; i<3; i++)
	{
		gData -> mWindow.draw(titleText[i]);
	}
	for (int i=0; i<18; i++)
	{
		gData -> mWindow.draw(charInfoText[i]);
	}
*/
}

void MarketState ::stop ()
{}

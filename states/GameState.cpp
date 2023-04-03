#include "headers/GameState.h"
#include "headers/MenuState.h"
#include "headers/GameOverState.h"
#include "headers/ChangeRationState.h"
#include "headers/ChangePlantingState.h"
#include "headers/LandTradeState.h"
#include "headers/EndTurnState.h"
#include "headers/LandDetailsState.h"
#include "headers/PeasantDetailsState.h"
#include "headers/GrainDetailsState.h"
#include "headers/Utility.h"

#include "headers/ConsoleInput.h"
#include <iostream>
#include <sstream>
#include <string>

GameState::GameState(GlobalDataRef gData) 
:gData(gData)
{
}

void GameState::init()
{
	gData -> mGameModel.startNew();
	//isNextTrial = false;

	texture = gData -> mAssets.getTexture(Textures::MainBackground);
	background.setTexture(texture);

	//prepare buttons
	sf::Sprite sprite;
	sf::Text text;

	sprite.setTexture(gData -> mAssets.getTexture(Textures::MenuButton));
	text.setFont(gData-> mAssets.getFont(Fonts::Main));
	text.setCharacterSize(18);
	text.setColor(sf::Color::Black);
	//preparation for number output

	//year button
	yearBtn	= Button (sprite, text, sf::Vector2f(10,10));
	yearBtn.setSize(sf::Vector2f(180,30));

	//population button
	populationBtn	= Button (sprite, text, sf::Vector2f(240,10));
	populationBtn.setSize(sf::Vector2f(180,30));
	//land button
	landBtn	= Button (sprite, text, sf::Vector2f(470,10));
	landBtn.setSize(sf::Vector2f(180,30));
	//grain button
	grainBtn	= Button (sprite, text, sf::Vector2f(700,10));
	grainBtn.setSize(sf::Vector2f(180,30));

	//ration button
	rationBtn	= Button (sprite, text, sf::Vector2f(10,200));
	rationBtn.setSize(sf::Vector2f(180,30));
	//planting button
	plantingBtn	= Button (sprite, text, sf::Vector2f(10,250));
	plantingBtn.setSize(sf::Vector2f(180,30));
	//trade button
	tradeBtn	= Button (sprite, text, sf::Vector2f(10,300));
	tradeBtn.setSize(sf::Vector2f(180,30));
	tradeBtn.setTextString(gData -> mStringsDB.getString(Trade));

	//exit button
	exitBtn	= Button (sprite, text, sf::Vector2f(10,700));
	exitBtn.setSize(sf::Vector2f(180,30));
	exitBtn.setTextString(gData -> mStringsDB.getString(Menu_exit));
	//next turn button
	endTurnBtn	= Button (sprite, text, sf::Vector2f(700,700));
	endTurnBtn.setSize(sf::Vector2f(180,30));
	endTurnBtn.setTextString(gData -> mStringsDB.getString(End_turn));
}

void GameState::handleInput(const sf::Event& event)
{
	if (exitBtn.isClicked(sf::Mouse::Left, gData -> mWindow))
	{		gData -> mStates.replaceState(StatePtr (new MenuState(gData)));	}

	if (populationBtn.isClicked(sf::Mouse::Left, gData -> mWindow))
	{		gData -> mStates.addState(StatePtr (new PeasantDetailsState(gData)));	}
	if (landBtn.isClicked(sf::Mouse::Left, gData -> mWindow))
	{		gData -> mStates.addState(StatePtr (new LandDetailsState(gData)));	}
	if (grainBtn.isClicked(sf::Mouse::Left, gData -> mWindow))
	{		gData -> mStates.addState(StatePtr (new GrainDetailsState(gData)));	}

	if (rationBtn.isClicked(sf::Mouse::Left, gData -> mWindow))
	{		gData -> mStates.addState(StatePtr (new ChangeRationState(gData)));	}
/*
	isNextTrial = false;
	int answer= askNumber();
	if ((answer<0)||(answer>7)) {isNextTrial = true;}

	if (answer == 0){gData -> mStates.removeState();} // back to MainMenu. 
	if (answer == 4){gData -> mStates.addState(StatePtr (new ChangeRationState(gData)));} 
	if (answer == 5){gData -> mStates.addState(StatePtr (new ChangePlantingState(gData)));} 
 	//if (answer == 6){gData -> mStates.addState(StatePtr (new LandTradeState(gData)));} 
 	//if (answer == 7){gData -> mStates.addState(StatePtr (new EndTurnState(gData)));} 
*/
}

void GameState::update (float dt)
{
	if ((gData -> mGameModel.getGameStatus()) != PLAY)
	{
		{gData -> mStates.addState(StatePtr (new GameOverState(gData)));}
	}

	grain = gData -> mGameModel.getGrainReport();
	land = gData -> mGameModel.getLandReport();
	peasants = gData -> mGameModel.getPeasantsReport();

	//buttons update
	std::ostringstream tempNumber;

	tempNumber<< (gData -> mGameModel.getYear());
	yearBtn.setTextString(gData -> mStringsDB.getString(Year) + tempNumber.str());
	tempNumber.str("");
	tempNumber<< peasants.total << " (" << peasants.total - peasants.atStart << ")";
	populationBtn.setTextString((gData -> mStringsDB.getString(Peasants)) + tempNumber.str());
	tempNumber.str("");
	tempNumber<< land.total<< " (" << land.total - land.atStart << ")";;
	landBtn.setTextString((gData -> mStringsDB.getString(Land)) + tempNumber.str());
	tempNumber.str("");
	tempNumber<< grain.total << " (" << grain.total - grain.atStart << ")";;
	grainBtn.setTextString((gData -> mStringsDB.getString(Grain)) + tempNumber.str());
	tempNumber.str("");
	tempNumber<<  gData -> mGameModel.getCurrentRation();
	rationBtn.setTextString((gData -> mStringsDB.getString(Ration)) + tempNumber.str());
	tempNumber.str("");
	//tempNumber<<  gData -> mGameModel.getCurrentRation();
	plantingBtn.setTextString((gData -> mStringsDB.getString(Planting)) + tempNumber.str());

	//std::cout<<peasants.total<<std::endl;
}

void GameState::draw(float dt)
{
	gData -> mWindow.draw(background);
	yearBtn.draw(gData -> mWindow);
	populationBtn.draw(gData -> mWindow);
	landBtn.draw(gData -> mWindow);
	grainBtn.draw(gData -> mWindow);
	rationBtn.draw(gData -> mWindow);
	plantingBtn.draw(gData -> mWindow);
	tradeBtn.draw(gData -> mWindow);
	exitBtn.draw(gData -> mWindow);
	endTurnBtn.draw(gData -> mWindow);

/*
	if (!isNextTrial) {showReport();}

	//std::cout<< (gData -> mStringsDB.getString(Report_state_menu) ) <<std::endl;
	while(!(gData -> mGameModel.noMessages()))
	{
		showMessage (gData -> mGameModel.getMessage());
	}
	std::cout<< gData -> mStringsDB.getString(Game_state_info) <<std::endl;
*/
}


void GameState::showReport()
{
/*
	grain = gData -> mGameModel.getGrainReport();
	land = gData -> mGameModel.getLandReport();
	peasants = gData -> mGameModel.getPeasantsReport();

	std::cout<<std::endl<<std::endl<<std::endl<<std::endl;
	//global report
	std::cout<< gData -> mStringsDB.getString(Year) << (gData -> mGameModel.getYear()) <<" ";
	std::cout<< gData -> mStringsDB.getString(Peasants) << peasants.total <<" ";
	std::cout<< gData -> mStringsDB.getString(Land) << land.total <<" ";
	std::cout<< gData -> mStringsDB.getString(Grain) << grain.total <<std::endl;

	//peasants detailed report
	std::cout<< gData -> mStringsDB.getString(Peasants_at_start) << peasants.atStart <<std::endl;
	if (peasants.starvation !=0) 
	{	std::cout<< gData -> mStringsDB.getString(Peasants_starvation) << peasants.starvation <<std::endl;}
	if (peasants.king_levy !=0) 
	{	std::cout<< gData -> mStringsDB.getString(Peasants_king_levy) << peasants.king_levy <<std::endl;}
	if (peasants.war !=0) 
	{	std::cout<< gData -> mStringsDB.getString(Peasants_war) << peasants.war <<std::endl;}
	if (peasants.looting !=0) 
	{	std::cout<< gData -> mStringsDB.getString(Peasants_looting) << peasants.looting <<std::endl;}
	if (peasants.disease !=0) 
	{	std::cout<< gData -> mStringsDB.getString(Peasants_disease) << peasants.disease <<std::endl;}
	if (peasants.death !=0) 
	{	std::cout<< gData -> mStringsDB.getString(Peasants_death) << peasants.death <<std::endl;}
	if (peasants.birth !=0) 
	{	std::cout<< gData -> mStringsDB.getString(Peasants_birth) << peasants.birth <<std::endl;}

	//land detailed report

	std::cout<< gData -> mStringsDB.getString(Land_at_start) << land.atStart <<std::endl;
	if (land.trade !=0) 
	{	std::cout<< gData -> mStringsDB.getString(Land_trade) << land.trade <<std::endl;}
	if (land.war !=0) 
	{	std::cout<< gData -> mStringsDB.getString(Land_war) << land.war <<std::endl;}
	std::cout<< gData -> mStringsDB.getString(Land_by_quality) <<std::endl;
	std::string tabs = "  ";
	std::cout<<"   "<<land.f100 <<tabs <<land.f80<<tabs <<land.f60<<tabs <<land.f40<<tabs <<land.f20<<tabs <<land.f0 <<std::endl;

	//grain detailed report
	std::cout<< gData -> mStringsDB.getString(Grain_at_start) << grain.atStart <<std::endl;
	std::cout<< gData -> mStringsDB.getString(Grain_food) << grain.forFood <<std::endl;
	if (grain.landDeals !=0) 
	{	std::cout<< gData -> mStringsDB.getString(Grain_trade) << grain.landDeals <<std::endl;}
	if (grain.seeds !=0) 
	{	std::cout<< gData -> mStringsDB.getString(Grain_seeds) << grain.seeds <<std::endl;}
	if (grain.rat !=0) 
	{	std::cout<< gData -> mStringsDB.getString(Grain_rat) << grain.rat <<std::endl;}
	if (grain.mercenaryCost !=0) 
	{	std::cout<< gData -> mStringsDB.getString(Grain_mercenary) << grain.mercenaryCost <<std::endl;}
	if (grain.warCaptured !=0) 
	{	std::cout<< gData -> mStringsDB.getString(Grain_war) << grain.warCaptured <<std::endl;}
	if (grain.harvest !=0) 
	{	std::cout<< gData -> mStringsDB.getString(Grain_crop_yield) << grain.harvest <<std::endl;}
	std::cout<< gData -> mStringsDB.getString(Grain_castle) << grain.castleExpences <<std::endl;
	std::cout<< gData -> mStringsDB.getString(Grain_tax) << grain.royalTax <<std::endl;

	std::cout<<std::endl<<std::endl;
*/
}

void GameState::showMessage(Message msg)
{
}

#pragma once

#include "State.h"
#include "Application.h"
#include "GameModel.h"
#include "ReportStruct.h"

#include "ResourceIdentifiers.h"
#include "Definitions.h"
#include "Button.h"
#include "SFML/Graphics.hpp"

//#include <string>


class GameState : public State
{
	public:
			GameState (GlobalDataRef gData);

        void init();
        void handleInput(const sf::Event& event);
        void update (float dt);
        void draw(float dt );
        
		void	stop(){};
		void	resume(){};
		void	pause(){};

	private:
		GlobalDataRef	gData;
		//bool	isStepComplete;
		bool	isNextTrial;
		
		void showReport();
		void showMessage(Message msg);

		report::grainReport	grain;
		report::landReport	land;
		report::peasantsReport	peasants;

        sf::Sprite  background;
		sf::Texture	texture;		

		Button		yearBtn;
		Button		rationBtn;
		Button		plantingBtn;
		Button		tradeBtn;
		Button		exitBtn;
		Button		endTurnBtn;

		Button		populationBtn;
		Button		landBtn;
		Button		grainBtn;
};

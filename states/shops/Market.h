#pragma once

#include "../../core/State.h"
#include "../../core/Application.h"
//#include "../../gui/Button.h"
#include "../../ResourceIdentifiers.h"
//#include "../../Definitions.h"
#include "SFML/Graphics.hpp"


class MarketState : public State
{
	public:
		MarketState (GlobalDataRef gData);

        	void init();
       		void handleInput(const sf::Event& event);
        	void update (float dt);
        	void draw(float dt );
		void stop();
        
	private:
		GlobalDataRef   gData;

        	//sf::Sprite  _background;

		sf::Text	titleText[3];
		sf::Text	charInfoText[18];
};

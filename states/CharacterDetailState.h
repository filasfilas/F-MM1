#pragma once

#include "../core/State.h"
#include "../core/Application.h"
//#include "../gui/Button.h"
#include "../ResourceIdentifiers.h"
//#include "../Definitions.h"
#include "SFML/Graphics.hpp"


class CharacterDetailState : public State
{
	public:
		CharacterDetailState (GlobalDataRef gData, Character* currentCharacter);

        	void init();
       		void handleInput(const sf::Event& event);
        	void update (float dt);
        	void draw(float dt );
		void stop();

		void changeCharacter (Character* newCharacter);
        
	private:
		GlobalDataRef   gData;
		Character* _character;
        	//sf::Sprite  _background;

		sf::Text	titleText[3];
		sf::Text	charInfoText[18];
};

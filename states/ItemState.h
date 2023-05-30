#pragma once
#include <vector>
#include <string>

#include "../core/State.h"
#include "../core/Application.h"
//#include "../gui/Button.h"
#include "../ResourceIdentifiers.h"
//#include "../Definitions.h"
#include "SFML/Graphics.hpp"

class ItemState : public State
{
	public:
		ItemState (GlobalDataRef gData, Character* character, std::string itemActionType);

        	void init();
       		void handleInput(const sf::Event& event);
        	void update (float dt);
        	void draw(float dt );
		void stop();

		//void removeItem (int id);
        
	private:
		GlobalDataRef   gData;
		std::string 	_itemActionType;
		Character* _character;
        	sf::RectangleShape _board;
		bool	_actionDone;
		int	_itemNum;

		sf::Text	_txtLabel[10];
};

#include "ViewAllCharState.h"
//#include "../gui/Utility.h"
//#include <iostream>

ViewAllCharState::ViewAllCharState(GlobalDataRef gData) 
: gData(gData)
{

}

void ViewAllCharState::init() {

}

void ViewAllCharState::handleInput(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
        {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			gData -> mStates.removeState();
		}
	}
}

void ViewAllCharState::update (float dt){
}

void ViewAllCharState::draw(float dt) {

	//temporary display clean. To delete when the state will be implemented.
	gData -> mWindow.clear(); //TO BE DELETED
}

void ViewAllCharState::stop ()
{}

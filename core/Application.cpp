#include "Application.h"
#include "../states/TitleState.h"
#include "../Definitions.h"
//#include<iostream>


Application::Application(){
    gData -> mWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), APP_NAME, sf::Style::Close);
    gData -> mWindow.setKeyRepeatEnabled(false);	
    loadResources();
    gData -> mStates.addState(StatePtr(new TitleState (gData))); //push TitleState in stack
    gData -> mStates.processStateChange();
}


void Application::run(){       
	sf::Clock clock; 
	float timeSinceLastUpdate = 0; 
	bool repaint = false;

	while ( !(gData -> mStates.isEmpty()) && (gData -> mWindow.isOpen()) ) 	{         
			timeSinceLastUpdate += (clock.restart()).asSeconds(); 
			while (timeSinceLastUpdate > TimePerFrame) { 
				timeSinceLastUpdate -= TimePerFrame; 
				repaint = true; 
		        	processInput();
		        	update(TimePerFrame); 
			} 
			if(repaint) {
				render(TimePerFrame); 
				repaint = false;
		 	}

			gData -> mStates.processStateChange();
	}
}


void Application::processInput(){
	sf::Event event;

	while (gData -> mWindow.pollEvent(event)) {
 		if (event.type == sf::Event::Closed) {
			gData -> mWindow.close();
		}
        	//pass event into StateStack
        	gData -> mStates.handleInput(event);
	}
}


void Application::render(float dt){
	gData -> mWindow.clear();
	gData -> mStates.draw(dt); // draw active states
	gData -> mWindow.display();
}

void Application::update(float dt){
	gData -> mStates.update(dt);
}

void Application::loadResources(){
	gData -> mStringsDB.setLanguage();
	gData -> mAssets.loadFont(Fonts::Main, "media/fonts/Square.ttf");
}

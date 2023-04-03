#pragma once

#include "../Definitions.h"
#include "../core/State.h"
#include "../core/Application.h"
#include "../ResourceIdentifiers.h"
#include "SFML/Graphics.hpp"

class TitleState : public State {
	public:
		TitleState (GlobalDataRef gData);

        	void init();
        	void stop();
        	void handleInput(const sf::Event& event);
        	void update (float dt);
        	void draw(float dt );

	private:
		GlobalDataRef	gData;
		float timer;
		int _currentSlide;
		const float SLIDE_DELAY = 10.0; //time to show one slide
		void loadData();
		void unloadData();
		sf::Sprite _background;
        	sf::Sprite  _slides[10];
		void nextSlide();

		sf::Text	titleText[4];
};

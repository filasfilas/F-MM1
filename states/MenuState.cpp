#include "MenuState.h"
#include "GameState.h"
#include "ViewAllCharState.h"
#include "../gui/Utility.h"
//#include <iostream>

MenuState::MenuState(GlobalDataRef gData) 
: gData(gData)
{
	gData -> mAssets.loadTexture(Textures::MainMenu, "media/images/MM1-map.png");
	gData -> mAssets.loadTexture(Textures::MenuButton, "media/images/gui/Button.png");
}

void MenuState::init() {
    int _screen_width = gData -> mWindow.getSize().x;
    int _screen_height = gData -> mWindow.getSize().y;
	_background.setTexture(gData -> mAssets.getTexture(Textures::MainMenu));
	_background.setOrigin(_background.getTextureRect().width/2, _background.getTextureRect().height/2);
	_background.setPosition(_screen_width/2, _screen_height/2);
	sf::Vector2f scale;
	scale.y = 1.0*_screen_height/ (_background.getTextureRect().height);
	scale.x = scale.y;
	_background.setScale(scale);

	//prepare buttons
	sf::Sprite sprite;
	sf::Text text;

	sprite.setTexture(gData -> mAssets.getTexture(Textures::MenuButton));
    sprite.setScale(1.5, 0.8);
	centerOrigin(sprite);

	text.setFont(gData-> mAssets.getFont(Fonts::Main));

	//create new character
	text.setString(gData -> mStringsDB.getString(CreateNewCharacter));
	centerOrigin(text);
	newCharBtn = Button (sprite, text, sf::Vector2f(_screen_width/2,100));

	//view all character
	text.setString(gData -> mStringsDB.getString(ViewAllCharacters));
	centerOrigin(text);
	viewAllBtn = Button (sprite, text, sf::Vector2f(_screen_width/2,200));

	//go to town
	text.setString(gData -> mStringsDB.getString(GoToTown));
	centerOrigin(text);
	playBtn = Button (sprite, text, sf::Vector2f(_screen_width/2,300));

	//exit button
	text.setString(gData -> mStringsDB.getString(ExitGame));
	centerOrigin(text);
	exitBtn = Button (sprite, text, sf::Vector2f(_screen_width/2,400));
}

void MenuState::handleInput(const sf::Event& event)
{
	if (viewAllBtn.isClicked(sf::Mouse::Left, gData -> mWindow))	{
		gData -> mStates.addState(StatePtr (new ViewAllCharState(gData)));
	}
/*
	if (newCharBtn.isClicked(sf::Mouse::Left, gData -> mWindow))	{
		gData -> mStates.addState(StatePtr (new CreateCharState(gData)));
	}

*/
	if (playBtn.isClicked(sf::Mouse::Left, gData -> mWindow))	{
		gData -> mStates.replaceState(StatePtr (new GameState(gData, 1)));
	}
	if (exitBtn.isClicked(sf::Mouse::Left, gData -> mWindow)) {
		gData -> mStates.removeState();
		gData -> mMusic.stop();
	}
	
//temporary town selector
	if (event.type == sf::Event::KeyReleased) {
		if ((event.key.code >= sf::Keyboard::Num1)&&(event.key.code <= sf::Keyboard::Num5)){
			gData -> mStates.replaceState(StatePtr(new GameState(gData, (event.key.code-26) )));
		}
		//temporary for test
		else if ((event.key.code == sf::Keyboard::Num9)){
			gData -> mStates.replaceState(StatePtr(new GameState(gData, 39 )));
		}
	}

}

void MenuState::update (float dt)
{}

void MenuState::draw(float dt) {
	gData -> mWindow.draw(_background);

	playBtn.draw(gData -> mWindow);
	newCharBtn.draw(gData -> mWindow);
    	viewAllBtn.draw(gData -> mWindow);
	exitBtn.draw(gData -> mWindow);
}

void MenuState::stop ()
{}

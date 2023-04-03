#include "MenuState.h"
//#include "GameState.h"
#include "../gui/Utility.h"
//#include <iostream>

MenuState::MenuState(GlobalDataRef gData) 
: gData(gData)
{
	gData -> mAssets.loadTexture(Textures::MainMenu, "media/images/MM1-map.png");
	gData -> mAssets.loadTexture(Textures::MenuButton, "media/images/gui/Button.png");
}

void MenuState::init() {
	_background.setTexture(gData -> mAssets.getTexture(Textures::MainMenu));
	_background.setOrigin(_background.getTextureRect().width/2, _background.getTextureRect().height/2);
	_background.setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
	sf::Vector2f scale;
	scale.y = 1.0*SCREEN_HEIGHT / (_background.getTextureRect().height);
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
	newCharBtn = Button (sprite, text, sf::Vector2f(SCREEN_WIDTH/2,100));
	newCharBtn.setTextAlign(HorizontalAlign::CENTER);

	//view all character
	text.setString(gData -> mStringsDB.getString(ViewAllCharacters));
	viewAllBtn = Button (sprite, text, sf::Vector2f(SCREEN_WIDTH/2,200));
	viewAllBtn.setTextAlign(HorizontalAlign::CENTER);

	//go to town
	text.setString(gData -> mStringsDB.getString(GoToTown));
	playBtn = Button (sprite, text, sf::Vector2f(SCREEN_WIDTH/2,300));
	playBtn.setTextAlign(HorizontalAlign::CENTER);

	//exit button
	text.setString(gData -> mStringsDB.getString(ExitGame));
	exitBtn = Button (sprite, text, sf::Vector2f(SCREEN_WIDTH/2,400));
	exitBtn.setTextAlign(HorizontalAlign::CENTER);
}

void MenuState::handleInput(const sf::Event& event)
{
	if (exitBtn.isClicked(sf::Mouse::Left, gData -> mWindow)) {
		gData -> mStates.removeState();
	}
/*
	if (playBtn.isClicked(sf::Mouse::Left, gData -> mWindow))	{
		gData -> mStates.replaceState(StatePtr (new GameState(gData)));
	}
	if (newCharBtn.isClicked(sf::Mouse::Left, gData -> mWindow))	{
		gData -> mStates.addState(StatePtr (new InstructionState(gData)));
	}
	if (viewAllBtn.isClicked(sf::Mouse::Left, gData -> mWindow))	{
		gData -> mStates.addState(StatePtr (new InstructionState(gData)));
	}
*/
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

#include "ViewAllCharState.h"
#include "CharacterDetailState.h"
#include "../model/character.h"
//#include "../gui/Utility.h"
//#include <iostream>

ViewAllCharState::ViewAllCharState(GlobalDataRef gData) 
: gData(gData)
{
	titleText[0].setString(gData -> mStringsDB.getString(ViewAllCharacters));
	titleText[1].setString(gData -> mStringsDB.getString(PressToViewChar));
	titleText[2].setString(gData -> mStringsDB.getString(EscToGoBack));
	int ChrSize [] = {30, 25, 25}; //font sizes	
	int textX [] = {150, 100, 150}; //X positions
	int textY [] = {10, 520, 550}; //Y positions

	for (int i=0; i<3; i++)
	{
		titleText[i].setFont(gData-> mAssets.getFont(Fonts::Main));
		titleText[i].setColor(sf::Color(255, 255, 255));
		titleText[i].setCharacterSize(ChrSize[i]);
		titleText[i].setPosition(textX[i], textY[i]);
	}
	for (int i=0; i<18; i++)
	{
		charInfoText[i].setFont(gData-> mAssets.getFont(Fonts::Main));
		charInfoText[i].setColor(sf::Color(255, 255, 255));
		charInfoText[i].setCharacterSize(16);
		charInfoText[i].setPosition(10, 50+25*i);
	}
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
		else if ((event.key.code >= sf::Keyboard::A)&&(event.key.code<=sf::Keyboard::Z)) {
			int num = int (event.key.code);
			Character* character = gData-> mGameModel._party._roster.getCharacter(num);
			if (character != nullptr){
				gData -> mStates.addState(StatePtr (new CharacterDetailState(gData, character)));
			}
		}
	}
}

void ViewAllCharState::update (float dt){
	std::string txt;
	Character* character;
	for (int i=0; i<18; i++)
	{
		txt = "";
		txt.push_back(char(0x41+i));
		txt += ")   ";
		character = gData-> mGameModel._party._roster.getCharacter(i);
		if (character != nullptr){
			txt = txt + character-> _name + "  "; 
			txt = txt + "(" + std::to_string(character-> _town) + ") ";
			txt = txt + " LVL " + std::to_string(character-> _level._permanent) + " ";
			switch (character->_class){
				case CLASS_KNIGHT: txt = txt + "Knight"; break;
				case CLASS_PALADIN: txt = txt + "Paladin"; break;
				case CLASS_CLERIC: txt = txt + "Cleric"; break;
				case CLASS_SORCERER: txt = txt + "Sorcerer"; break;
				case CLASS_ROBBER: txt = txt + "Robber"; break;
				case CLASS_ARCHER: txt = txt + "Archer"; break;
			}
		}
		charInfoText[i].setString(txt);
	}
}

void ViewAllCharState::draw(float dt) {

	//temporary display clean. To delete when the state will be implemented.
	gData -> mWindow.clear(); //TO BE DELETED

	for (int i=0; i<3; i++)
	{
		gData -> mWindow.draw(titleText[i]);
	}
	for (int i=0; i<18; i++)
	{
		gData -> mWindow.draw(charInfoText[i]);
	}
}

void ViewAllCharState::stop ()
{}

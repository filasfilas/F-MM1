#include "CharacterDetailState.h"
#include "../model/character.h"
//#include "../gui/Utility.h"
//#include <iostream>

CharacterDetailState::CharacterDetailState (GlobalDataRef gData, Character* currentCharacter)
: gData(gData)
, _character(currentCharacter)
{

	titleText[0].setString(gData -> mStringsDB.getString(EscToGoBack));

	int ChrSize [] = {25, 25, 25}; //font sizes	
	int textX [] = {150, 100, 150}; //X positions
	int textY [] = {550, 520, 550}; //Y positions

	for (int i=0; i<3; i++)
	{
		titleText[i].setFont(gData-> mAssets.getFont(Fonts::Main));
		titleText[i].setColor(sf::Color(255, 255, 255));
		titleText[i].setCharacterSize(ChrSize[i]);
		titleText[i].setPosition(textX[i], textY[i]);
	}
	for (int i=0; i<2; i++)
	{
		charInfoText[i].setFont(gData-> mAssets.getFont(Fonts::Main));
		charInfoText[i].setColor(sf::Color(255, 255, 255));
		charInfoText[i].setCharacterSize(16);
		charInfoText[i].setPosition(10, 50+25*i);
	}
}

void CharacterDetailState::changeCharacter (Character* newCharacter){
	_character = newCharacter;
}

void CharacterDetailState::init() {

}

void CharacterDetailState::handleInput(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
        {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			gData -> mStates.removeState();
		}
	}
}

void CharacterDetailState::update (float dt){
	std::string txt;

	txt =  _character-> _name + "    : ";
	if (_character->_sex == MALE) {txt += "Male    ";}
	if (_character->_sex == FEMALE) {txt += "Female  ";}
	
	switch (_character->_class){
		case CLASS_KNIGHT: txt = txt + "Knight"; break;
		case CLASS_PALADIN: txt = txt + "Paladin"; break;
		case CLASS_CLERIC: txt = txt + "Cleric"; break;
		case CLASS_SORCERER: txt = txt + "Sorcerer"; break;
		case CLASS_ROBBER: txt = txt + "Robber"; break;
		case CLASS_ARCHER: txt = txt + "Archer"; break;
	}
	charInfoText[0].setString(txt);
}

void CharacterDetailState::draw(float dt) {

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

void CharacterDetailState::stop ()
{}

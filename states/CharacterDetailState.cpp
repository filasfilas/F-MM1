#include "CharacterDetailState.h"
#include "ItemState.h"
#include "../model/character.h"
//#include "../gui/Utility.h"
//#include <iostream>

CharacterDetailState::CharacterDetailState (GlobalDataRef gData, Character* currentCharacter)
: gData(gData)
, _character(currentCharacter)
{
	_charId = 0;
	sf::Text txt;

	//int ChrSize [] = {16, 16, 16}; //font sizes	
	int textX [] = {10, 50, 200, 300, 400, 500,  10, 10, 10, 10, 10, 10, 10, 10,
			250, 250, 250, 250, 400, 500, 500, 500, 500, 10, 500,
			10, 10, 10, 10, 10, 10, 400, 400, 400, 400, 400, 400,
			10, 10, 10, 350, 350, 350, 350, 550, 550, 550, 550}; //X positions 
	int textY [] = {10, 10, 10, 10, 10, 10, 40, 60, 80, 100, 120, 140, 160, 200,
			40, 80, 120, 160, 40, 40, 80, 120, 160, 250, 250,
			300, 320, 340, 360, 380, 400, 300, 320, 340, 360, 380, 400,
			460, 480, 520, 460, 480, 500, 520, 460, 480, 500, 520}; //Y positions

	for (int i=0; i<LABELS_COUNT; i++)
	{
		_txtLabel[i].setFont(gData-> mAssets.getFont(Fonts::Main));
		_txtLabel[i].setColor(sf::Color(255, 255, 255));
		_txtLabel[i].setCharacterSize(16);
		_txtLabel[i].setPosition(textX[i], textY[i]);
	}

	_txtLabel[37].setString ("'Q' - quick reference");	
	_txtLabel[38].setString ("'1-6' - change character");
	_txtLabel[39].setString ("'ESC' - to go back");
	_txtLabel[40].setString ("'C' - cast a spell");
	_txtLabel[41].setString ("'D' - discard");
	_txtLabel[42].setString ("'E' - equip");
	_txtLabel[43].setString ("'G' - gather");
	_txtLabel[44].setString ("'R' - remove");
	_txtLabel[45].setString ("'S' - share");
	_txtLabel[46].setString ("'T' - trade item");
	_txtLabel[47].setString ("'U' - use");
}

void CharacterDetailState::changeCharacter (Character* newCharacter){
	_character = newCharacter;
	charDataUpdate();
}

void CharacterDetailState::changeCharacter (int characterId){
	_charId = characterId;
	_character = gData-> mGameModel._party.getCharacter(characterId);
	charDataUpdate();
}

void CharacterDetailState::init() {
	charDataUpdate();
}

void CharacterDetailState::handleInput(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
        {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			gData -> mStates.removeState();
		}
		else if ((event.key.code >= sf::Keyboard::Num1)&&(event.key.code<=sf::Keyboard::Num6)) {
			_charId = int (event.key.code-27);
			changeCharacter (_charId);
		}
		else if (event.key.code == sf::Keyboard::R) {
			gData -> mStates.addState(StatePtr(new ItemState(gData, _character, "Remove")));
		}
		else if (event.key.code == sf::Keyboard::D) {
			gData -> mStates.addState(StatePtr(new ItemState(gData, _character, "Drop")));
		}
		else if (event.key.code == sf::Keyboard::E) {
			gData -> mStates.addState(StatePtr(new ItemState(gData, _character, "Equip")));
		}
		else if (event.key.code == sf::Keyboard::S) {
			gData -> mStates.addState(StatePtr(new ItemState(gData, _character, "Share")));
		}
		else if (event.key.code == sf::Keyboard::G) {
			gData -> mStates.addState(StatePtr(new ItemState(gData, _character, "Gather")));
		}
		else if (event.key.code == sf::Keyboard::T) {
			gData -> mStates.addState(StatePtr(new ItemState(gData, _character, "Trade")));
		}
	}
	charDataUpdate();
}

void CharacterDetailState::update (float dt){
}

void CharacterDetailState::draw(float dt) {

	//temporary display clean. To delete when the state will be implemented.
	gData -> mWindow.clear(); //TO BE DELETED

	for (int i=0; i< LABELS_COUNT; i++)
	{
		gData -> mWindow.draw(_txtLabel[i]);
	}
}

void CharacterDetailState::stop ()
{}

void CharacterDetailState::charDataUpdate (){
	_txtLabel[0].setString (std::to_string(_charId+1));
	_txtLabel[1].setString (_character-> _name);

	if (_character->_sex == MALE) {_txtLabel[2].setString ("Male");}
	if (_character->_sex == FEMALE) {_txtLabel[2].setString ("Female");}

	switch (_character->_alignment){
		case ALIGN_EVIL: _txtLabel[3].setString ("Evil"); break;
		case ALIGN_NEUTRAL: _txtLabel[3].setString ("Neutral"); break;
		case ALIGN_GOOD: _txtLabel[3].setString ("Good"); break;
	}
	switch (_character->_race){
		case HUMAN: _txtLabel[4].setString ("Human"); break;
		case ELF: _txtLabel[4].setString ("Elf"); break;
		case DWARF: _txtLabel[4].setString ("Dwarf"); break;
		case GNOME: _txtLabel[4].setString ("Gnome"); break;
		case HALF_ORC: _txtLabel[4].setString ("Half-Orc"); break;
	}
	switch (_character->_class){
		case CLASS_KNIGHT: _txtLabel[5].setString ("Knight"); break;
		case CLASS_PALADIN: _txtLabel[5].setString ("Paladin"); break;
		case CLASS_CLERIC: _txtLabel[5].setString ("Cleric"); break;
		case CLASS_SORCERER: _txtLabel[5].setString ("Sorcerer"); break;
		case CLASS_ROBBER: _txtLabel[5].setString ("Robber"); break;
		case CLASS_ARCHER: _txtLabel[5].setString ("Archer"); break;
	}

	_txtLabel[6].setString ("Intellect = " + std::to_string(_character->_intellect._temporary));
	_txtLabel[7].setString ("Might = " + std::to_string(_character->_might._temporary));
	_txtLabel[8].setString ("Personality = " + std::to_string(_character->_personality._temporary));
	_txtLabel[9].setString ("Endurance = " + std::to_string(_character->_endurance._temporary));
	_txtLabel[10].setString ("Speed = " + std::to_string(_character->_speed._temporary));
	_txtLabel[11].setString ("Accuracy = " + std::to_string(_character->_accuracy._temporary));
	_txtLabel[12].setString ("Luck = " + std::to_string(_character->_luck._temporary));

	Condition cond = _character -> getWorstCondition();
	std::string txt = "Condition = ";
	switch (cond) {
		case GOOD: txt = txt + "Good"; break;
		case ERADICATED: txt = txt + "Eradicated"; break;
		case DEAD: txt = txt + "Dead"; break;
		case STONED: txt = txt + "Stoned"; break;
		case UNCONSCIOUS: txt = txt + "Unconscious"; break;
		case PARALYZED: txt = txt + "Paralyzed"; break;
		case POISONED: txt = txt + "Poisoned"; break;
		case DISEASED: txt = txt + "Diseased"; break;
		case SILENCED: txt = txt + "Silenced"; break;
		case BLINDED: txt = txt + "Blinded"; break;
		case ASLEEP: txt = txt + "Asleep"; break;
	}
	_txtLabel[13].setString (txt);

	_txtLabel[14].setString ("Level = " + std::to_string(_character->_level._temporary));	
	_txtLabel[15].setString ("SP = " + std::to_string(_character->_SP._temporary) + " / " + std::to_string(_character->_SP._permanent));	
	_txtLabel[16].setString ("HP = " + std::to_string(_character->_HP._temporary) + " / " + std::to_string(_character->_HP._permanent));	
	_txtLabel[17].setString ("AC = " + std::to_string(_character->_AC._temporary));	
	_txtLabel[18].setString ("Age = " + std::to_string(_character->_age._permanent));
	_txtLabel[19].setString ("Experience = " + std::to_string(_character->_experience));	
	_txtLabel[20].setString ("Gems = " + std::to_string(_character->_gems));
	_txtLabel[21].setString ("Gold = " + std::to_string(_character->_gold));
	_txtLabel[22].setString ("Food = " + std::to_string(_character->_food));

	_txtLabel[23].setString ("--------<EQUIPPED>-----------------------------------");
	_txtLabel[24].setString ("<BACKPACK>-------------------------------------");

	for (int i=0; i<6; i++) {
		txt = std::to_string(i+1) + ") ";
		txt = txt + (gData -> mGameModel._items.getName(_character->getEquipped(i)));
		_txtLabel[25+i].setString(txt);

		txt="";
		txt.push_back(static_cast<char>(0x41+i));
		txt = txt + ") ";
		txt = txt + (gData -> mGameModel._items.getName(_character->getBackpack(i)));
		_txtLabel[31+i].setString(txt);			
	}
}

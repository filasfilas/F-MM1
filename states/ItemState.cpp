#include "ItemState.h"
#include "../model/character.h"
//#include "../gui/Utility.h"
//#include <iostream>

ItemState::ItemState (GlobalDataRef gData, Character* character, std::string itemActionType)
: gData(gData)
, _character (character)
, _itemActionType(itemActionType)
{
	_actionDone = false;
	_itemNum =0;

	_board.setSize(sf::Vector2f(600, 450));
	_board.setPosition(sf::Vector2f(300, 450));
	_board.setFillColor(sf::Color(0,0,0));

	int textX [] = {350, 350, 350, 350}; //X positions
	int textY [] = {460, 480, 500, 520}; //Y positions
	for (int i=0; i<10; i++)
	{
		_txtLabel[i].setFont(gData-> mAssets.getFont(Fonts::Main));
		_txtLabel[i].setColor(sf::Color(255, 255, 255));
		_txtLabel[i].setCharacterSize(16);
		_txtLabel[i].setPosition(textX[i], textY[i]);
	}
	if (_itemActionType == "Remove") _txtLabel[0].setString ("Remove what item? '1-6'");
	if (_itemActionType == "Drop") _txtLabel[0].setString ("Discard what item? 'A-F'");
	if (_itemActionType == "Equip") _txtLabel[0].setString ("Equip what item? 'A-F'");
	if (_itemActionType == "Share") _txtLabel[0].setString ("Share what?");
	if (_itemActionType == "Gather") _txtLabel[0].setString ("Gather what?");
	if (_itemActionType == "Trade") _txtLabel[0].setString ("Transfer what item? 'A-F'");

	if ((_itemActionType == "Gather") || (_itemActionType == "Share")) {
		_txtLabel[1].setString ("'G' - gold");
		_txtLabel[2].setString ("'E' - gems");
		_txtLabel[3].setString ("'F' - food");
	}
}


void ItemState::init() {
}

void ItemState::handleInput(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
        {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			gData -> mStates.removeState();
		}
		else if ((_itemActionType=="Remove")&&(event.key.code >= sf::Keyboard::Num1)&&(event.key.code<=sf::Keyboard::Num6)) {
			int itemNum = int (event.key.code-27);
			_actionDone = (gData->mGameModel.removeItem(_character, itemNum));
		}
		else if ((_itemActionType=="Drop")&&(event.key.code >= sf::Keyboard::A)&&(event.key.code<=sf::Keyboard::F)) {
			int itemNum = int (event.key.code);
			gData->mGameModel.dropItem(_character, itemNum);
			_actionDone = true;
		}
		else if ((_itemActionType=="Equip")&&(event.key.code >= sf::Keyboard::A)&&(event.key.code<=sf::Keyboard::F)) {
			int itemNum = int (event.key.code);
			_actionDone = (gData->mGameModel.equipItem(_character, itemNum));
		}
		else if (_itemActionType=="Gather") {
			std::string resource;
			if (event.key.code == sf::Keyboard::G) { resource = "gold"; _actionDone = true;}
			else if (event.key.code == sf::Keyboard::E) { resource = "gems"; _actionDone = true;}
			else if (event.key.code == sf::Keyboard::F) { resource = "food"; _actionDone = true;}
			_character->addStock(resource, gData->mGameModel._party.gatherAll(resource)); 

		}
		else if (_itemActionType=="Share") {
			std::string resource;
			if (event.key.code == sf::Keyboard::G) { resource = "gold"; _actionDone = true;}
			else if (event.key.code == sf::Keyboard::E) { resource = "gems"; _actionDone = true;}
			else if (event.key.code == sf::Keyboard::F) { resource = "food"; _actionDone = true;}
			gData->mGameModel._party.share(resource);
		}
		else if ((_itemActionType=="Trade")&&(event.key.code >= sf::Keyboard::A)&&(event.key.code<=sf::Keyboard::F)) {
			_itemNum = int (event.key.code);
			int _itemTransferID = (_character->getBackpack(_itemNum));
			if (_itemTransferID != 0) _itemActionType = "Trade-step2";
		}
		else if ((_itemActionType=="Trade-step2")&&(event.key.code >= sf::Keyboard::Num1)&&(event.key.code<=sf::Keyboard::Num6)) {
			Character* newCharacter = gData->mGameModel._party.getCharacter(int (event.key.code-27));
			gData->mGameModel.transferItem(_character,  newCharacter, _itemNum);
			_actionDone = true;
		}
	}
}

void ItemState::update (float dt){
	if (_actionDone) {
		gData -> mStates.removeState();
	}
	if (_itemActionType == "Trade-step2") {
		_txtLabel[1].setString (gData -> mGameModel._items.getName(_character->getBackpack(_itemNum)));
		_txtLabel[2].setString ("Transfer to whom? '1-6'");
	}
}

void ItemState::draw(float dt) {

	gData -> mWindow.draw(_board);

	for (int i=0; i< 10; i++)
	{
		gData -> mWindow.draw(_txtLabel[i]);
	}
}

void ItemState::stop ()
{}

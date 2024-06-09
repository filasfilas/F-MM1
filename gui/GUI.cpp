#include "GUI.h"
#include "Utility.h"
#include "../states/CharacterDetailState.h"
#include <iostream>

GUI::GUI(sf::RenderWindow* target, GlobalDataRef gData)
:window (target)
,_gData(gData)
, _msgBox(window, window->getSize().x,  window->getSize().y)
{
	_msgBox.setFont(&(gData-> mAssets.getFont(Fonts::Main)));

	gData -> mAssets.loadTexture(Textures::Face, "../media/images/gui/fff.png");
	for (int i=0; i<6; i++){
		_faces.push_back(new Face(window, _gData, i));
	}		
	for (int i=0; i<6; i++){
		//std::function<void(int)> pFunc = GUI::showCharacterInfo;
		//_faces[i] -> setCallback(pFunc);
	}
}


void GUI::draw()
{
	_msgBox.draw();
	for (int i=0; i<6; i++){
		_faces[i]->draw();
	}
	//window->draw(mShape);
	//window->draw(mText);
}

void GUI::handleInput()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		for (int i=0; i<6; i++){
			_faces[i]->handleInput();
		}
	}
}

void GUI::update()
{
	_msgBox.setTextString(_gData -> mGameModel.getMessage());
}

void GUI::makeStep(){
	_msgBox.clean();
}

void GUI::showCharacterInfo(int id){
	Character* character = _gData-> mGameModel._party.getCharacter(id);
	if (character != nullptr){
		_gData -> mStates.addState(StatePtr (new CharacterDetailState(_gData, character)));
	}

}



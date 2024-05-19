#include "GUI.h"
#include "Utility.h"

GUI::GUI(sf::RenderWindow* target)
:window (target)
, _msgBox(window, window->getSize().x,  window->getSize().y)
{
	for (int i=0; i<6; i++){
		_faces.push_back(new Face(window, i));
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


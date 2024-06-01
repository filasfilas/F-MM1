#pragma once

#include <vector>
#include "SFML/Graphics.hpp"

#include "../core/Application.h"
#include "../gui/MessageBox.h"
#include "../gui/Face.h"

class GUI
{
	public:

		GUI(sf::RenderWindow* target, GlobalDataRef gData);
					
		//void setTextString(sf::String str);
		void draw();
		void handleInput();
		void update();


	private:
		sf::RenderWindow* 	window;
		GlobalDataRef _gData;
		MessageBox  _msgBox;
		std::vector<Face*>	_faces;

		void showCharacterInfo(int id);
};

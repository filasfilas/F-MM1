#pragma once

#include <vector>
#include "SFML/Graphics.hpp"

#include "../gui/MessageBox.h"
#include "../gui/Face.h"

class GUI
{
	public:

		GUI(sf::RenderWindow* target);
					
		//void setTextString(sf::String str);
		void draw();


	private:
		sf::RenderWindow* 	window;
		MessageBox  _msgBox;
		std::vector<Face*>	_faces;
};

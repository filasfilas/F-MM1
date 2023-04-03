#pragma once
#include "../media/localization/MultiLangIdentifiers.h"
#include <map>
#include "SFML/System/String.hpp"
#include <string>


class MultiLangManager
{
	public:
		MultiLangManager();
		void         setLanguage ();
		sf::String   getString (StringID) const;


	private:
		std::map <int, sf::String>	_mStrings;

		std::string	_currentLanguage;
		void		loadLangFile (std::string filename);

};

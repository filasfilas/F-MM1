#include "MultiLangManager.h"
#include <fstream>
#include <iostream>
#include <locale>

MultiLangManager::MultiLangManager(){
	//std::locale::global( std::locale( "ru_RU.UTF8" ) );
}

void MultiLangManager::loadLangFile (std::string filename){
	std::wifstream file(filename);

	std::wstring str;
	for (int i=0; i< STRING_COUNT; i++)	{
		getline (file, str);
		_mStrings[i]=str;
	}
}


sf::String MultiLangManager::getString (StringID name) const{
	return _mStrings.at(name);
}


void MultiLangManager::setLanguage(){
	std::string language = "ENG";
	language = "ENG";
/*
	int number;
	while(true)	{
		std::cin>>number;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767,'\n');
		}
		else {
			std::cin.ignore(32767,'\n');
			if(number>=1 and number< 3)	{break;}
		}	
	}
	if (number ==2) {language = "RUS";}
	if (currentLanguage == language) {return;}
*/

	_currentLanguage = language;
	std::string filename = "media/localization/strings_"+language+".txt";
	loadLangFile (filename);
}


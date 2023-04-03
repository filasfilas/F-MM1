#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../ResourceIdentifiers.h"
#include <map>
#include <string>


class ResourceManager
{
	public:
		void            loadTexture (Textures::ID name, const std::string& filename);
		sf::Texture&    getTexture (Textures::ID name);
		void            deleteTexture (Textures::ID name);

		void            loadFont (Fonts::ID name, const std::string& filename);
		sf::Font&       getFont (Fonts::ID name);
		void            deleteFont (Fonts::ID name);

		void                loadSoundBuffer (Sounds::ID name, const std::string& filename);
		sf::SoundBuffer&    getSoundBuffer (Sounds::ID name);
		void                deleteSoundBuffer (Sounds::ID name);

	private:
		std::map<Textures::ID, sf::Texture>  	_mTextures;
		std::map<Fonts::ID, sf::Font> 		_mFonts;	
		std::map<Sounds::ID, sf::SoundBuffer> 	_mSounds;	
};

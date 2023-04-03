#include "ResourceManager.h"


void ResourceManager::loadTexture (Textures::ID name, const std::string& filename){
	sf::Texture texture;
	if (texture.loadFromFile(filename)) {
		_mTextures[name]=texture;
	}
}

void ResourceManager::loadFont (Fonts::ID name, const std::string& filename){
	sf::Font font;
	if (font.loadFromFile(filename)) {
		_mFonts[name]=font;
	}
}

void ResourceManager::loadSoundBuffer (Sounds::ID name, const std::string& filename){
	sf::SoundBuffer sound;
	if (sound.loadFromFile(filename)) {
		_mSounds[name]=sound;
	}
}



sf::Texture& ResourceManager::getTexture (Textures::ID name){
	return _mTextures.at(name);
}

sf::Font& ResourceManager::getFont (Fonts::ID name){
	return _mFonts.at(name);
}

sf::SoundBuffer& ResourceManager::getSoundBuffer (Sounds::ID name){
	return _mSounds.at(name);
}


void ResourceManager::deleteTexture (Textures::ID name){
	if (_mTextures.find(name) == _mTextures.end()) {return;}
	_mTextures.erase(name);
}

void ResourceManager::deleteFont (Fonts::ID name){
	if (_mFonts.find(name) == _mFonts.end()) {return;}
	_mFonts.erase(name);
}

void ResourceManager::deleteSoundBuffer (Sounds::ID name){
	if (_mSounds.find(name) == _mSounds.end()) {return;}
	_mSounds.erase(name);
}
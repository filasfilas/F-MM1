#pragma once
#include "SFML/Audio.hpp"
#include "../ResourceIdentifiers.h"
#include <map>
#include <string>


class MusicPlayer
{
    public:
        MusicPlayer();
        void play(Music::ID theme);
        void stop();

        void setPaused(bool paused);
        void setVolume(float volume);
    
    private:
        sf::Music   _music;
        float       _volume;
        std::map <Music::ID, std::string> _mFiles;
};

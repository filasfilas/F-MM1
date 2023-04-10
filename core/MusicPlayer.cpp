#include "MusicPlayer.h"


MusicPlayer::MusicPlayer()
: _mMusic()
, _mFiles()
, _mVolume (100.f)
{
    _mFiles[Music::MainTheme] = "media/music/MM1-main.ogg";
    _mFiles[Music::TownTheme] = "media/music/MM1-town.ogg";
}


void MusicPlayer::play(Music::ID theme){
    std::string filename = _mFiles[theme];
    if (!_mMusic.openFromFile(filename)) {
        throw std::runtime_error("Music " + filename + " could not be loaded.");
    }
    _mMusic.setVolume(_mVolume);
    _mMusic.setLoop(true);
    _mMusic.play();
}

void MusicPlayer::stop(){
    _mMusic.stop();
}

void MusicPlayer::setPaused(bool paused){
    if (paused) {_mMusic.pause();}
    else {_mMusic.play();}
}

void MusicPlayer::setVolume(float volume){
    if (volume <0) volume =0.0;
    if (volume > 100.0) volume =100.0;
    _mMusic.setVolume (volume);
}

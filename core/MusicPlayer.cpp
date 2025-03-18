#include "MusicPlayer.h"


MusicPlayer::MusicPlayer()
: _music()
, _mFiles()
, _volume (100.f)
{
    _mFiles[Music::MainTheme] = "media/music/MM1-main.ogg";
    _mFiles[Music::TownTheme] = "media/music/MM1-town.ogg";
}


void MusicPlayer::play(Music::ID theme){
    std::string filename = _mFiles[theme];
    if (!_music.openFromFile(filename)) {
        throw std::runtime_error("Music " + filename + " could not be loaded.");
    }
    _music.setVolume(_volume);
    _music.setLoop(true);
    _music.play();
}

void MusicPlayer::stop(){
    _music.stop();
}

void MusicPlayer::setPaused(bool paused){
    if (paused) {_music.pause();}
    else {_music.play();}
}

void MusicPlayer::setVolume(float volume){
    _volume = volume;
    if (_volume <0) _volume =0.0;
    if (_volume > 100.0) _volume =100.0;
    _music.setVolume (_volume);
}

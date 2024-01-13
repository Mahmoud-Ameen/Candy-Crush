#include "MusicPlayer.h"

MusicPlayer::MusicPlayer(std::string musicPath) {
    //loading a nice song
    buffBuff.loadFromFile(musicPath);
    aNiceSong.setBuffer(buffBuff);
}

void MusicPlayer::playANiceSong(bool loop, int volume) {
    if(aNiceSong.getStatus() != sf::SoundSource::Playing) {
        aNiceSong.play();
        aNiceSong.setVolume(volume);
        aNiceSong.setLoop(loop);
    }
}

void MusicPlayer::pauseTheNiceSong() {
    if(aNiceSong.getStatus() == sf::SoundSource::Playing) {
        aNiceSong.pause();
    }
}

MusicPlayer::~MusicPlayer(){
//        aNiceSong.stop();
}
//
// Created by MAHMOUD on 1/3/2024.
//

#ifndef CANDYCRUSH_MUSICPLAYER_H
#define CANDYCRUSH_MUSICPLAYER_H


#include "SFML/Audio/Music.hpp"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"
#include <iostream>

class MusicPlayer {
    sf::Sound aNiceSong;
    sf::SoundBuffer buffBuff;
public:
    MusicPlayer(std::string file);
    void playANiceSong(bool loop, int volume);
    void pauseTheNiceSong();
    ~MusicPlayer();
};


#endif //CANDYCRUSH_MUSICPLAYER_H

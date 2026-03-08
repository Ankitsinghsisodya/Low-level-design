#pragma once 

#include<bits/stdc++.h>
#include<Song.hpp>
using namespace std;

class IAudioOutputDevice 
{
    public:
        virtual ~IAudioOutputDevice() {}
        virtual void playAudio(Song* song) = 0;
};
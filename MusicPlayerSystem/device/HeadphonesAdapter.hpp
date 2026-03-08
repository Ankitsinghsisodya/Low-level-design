#pragma once 

#include<bits/stdc++.h>
#include<IAudioOutputDevice.hpp>
#include<HeadphonesAPI.hpp>
using namespace std;

class HeadphonesAdapter : public IAudioOutputDevice
{
    private:
        HeadphonesAPI* headphonesApi;
    public:
        HeadphonesAdapter(HeadphonesAPI* headphonesApi)
        {
            this->headphonesApi = headphonesApi;
        }
        void playAudio(Song* song) override 
        {
            string payload = song->getTitle() + " by " + song->getArtist();
            headphonesApi->playSoundViaJack(payload);
        }
};
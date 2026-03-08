#pragma once 

#include<bits/stdc++.h>
#include<Song.hpp>
#include<WiredSpeakerAPI.hpp>
#include<IAudioOutputDevice.hpp>
using namespace std;

class WiredSpeakerAdapter : public IAudioOutputDevice
{
    private:
        WiredSpeakerAPI* wiredApi;
    public:
        WiredSpeakerAdapter(WiredSpeakerAPI* wiredApi)
        {
            this->wiredApi = wiredApi;
        }
        void playAudio(Song* song)
        {
            string payload = song->getTitle() + " by " + song->getArtist();
            wiredApi->playSoundViaCable(payload);
        }
};
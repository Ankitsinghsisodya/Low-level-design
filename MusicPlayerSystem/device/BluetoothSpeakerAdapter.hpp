#pragma once 

#include<bits/stdc++.h>
#include<IAudioOutputDevice.hpp>
#include<BluetoothSpeakerAPI.hpp>
#include<Song.hpp>
using namespace std;

class BluetoothSpeakerAdapter : public IAudioOutputDevice 
{
    private:
        BlutetoothSpeakerAPI* bluetoothApi;
    public:
        BluetoothSpeakerAdapter(BlutetoothSpeakerAPI* bluetoothApi)
        {
            this->bluetoothApi = bluetoothApi;
        }

        void playAudio(Song* song)
        {
            string payload = song->getTitle() + " by " + song->getArtist();
            bluetoothApi->playSoundViaBlutetooth(payload);
        }
};
#pragma once 

#include<bits/stdc++.h>
using namespace std;

class WiredSpeakerAPI
{
    public:
        void playSoundViaCable(const string& data)
        {
            cout << "[WiredSpeaker] Playing: " << data << "\n";
        }
};
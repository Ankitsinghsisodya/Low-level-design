#pragma once 

#include<bits/stdc++.h>
using namespace std;

class BlutetoothSpeakerAPI
{
    public:
        void playSoundViaBlutetooth(const string& data)
        {
              cout << "[BluetoothSpeaker] Playing: " << data << "\n";
        }
};
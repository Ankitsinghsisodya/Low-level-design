#pragma once 

#include<bits/stdc++.h>
#include<IAudioOutputDevice.hpp>
#include<BluetoothSpeakerAdapter.hpp>
#include<WiredSpeakerAdapter.hpp>
#include<HeadphonesAdapter.hpp>
#include<DeviceType.hpp>
using namespace std;

class DeviceFactory
{
    public:
        static IAudioOutputDevice* createDevice(DeviceType deviceType)
        {
            if(deviceType == DeviceType::BLUETOOTH)
            {
                return new BluetoothSpeakerAdapter(new BlutetoothSpeakerAPI());
            }
            else if(deviceType == DeviceType::HEADPHONES)
            {
                return new HeadphonesAdapter(new HeadphonesAPI());
            }
            else 
            {
                return new WiredSpeakerAdapter(new WiredSpeakerAPI());
            }
        }
};
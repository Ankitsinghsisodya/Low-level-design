#pragma once

#include <bits/stdc++.h>
#include <IAudioOutputDevice.hpp>
#include <DeviceType.hpp>
#include <DeviceFactory.hpp>
using namespace std;

class DeviceManager
{
private:
    static DeviceManager *instance;
    IAudioOutputDevice *currentOutputDevice;
    DeviceManager()
    {
        currentOutputDevice = nullptr;
    }

public:
    static DeviceManager *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new DeviceManager();
        }
        return instance;
    }
    void connect(DeviceType devicetype)
    {
        if (currentOutputDevice)
        {
            delete currentOutputDevice;
        }
        currentOutputDevice = DeviceFactory::createDevice(devicetype);

        switch (devicetype)
        {
        case DeviceType::BLUETOOTH:
            cout << "Bluetooth device connected \n";
            break;
        case DeviceType::WIRED:
            cout << "Wired device connected \n";
            break;
        case DeviceType::HEADPHONES:
            cout << "Headphones connected \n";
        }
    }
    IAudioOutputDevice *getOutputDevice()
    {
        if (!currentOutputDevice)
        {
            throw runtime_error("No output device is connected.");
        }
        return currentOutputDevice;
    }

    bool hasOutputDevice()
    {
        return currentOutputDevice != nullptr;
    }
};

DeviceManager *DeviceManager::instance = nullptr;
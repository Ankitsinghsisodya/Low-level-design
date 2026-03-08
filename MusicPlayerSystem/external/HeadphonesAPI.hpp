#pragma once

#include<bits/stdc++.h>
using namespace std;

class HeadphonesAPI
{
    public:
        void playSoundViaJack(const string& data)
        {
             cout << "[Headphones] Playing: " << data << "\n";
        }
};
#pragma once 

#include<bits/stdc++.h>
using namespace std;

class TimeUtils{
    public:
        static string getCurrentTime()
        {
            time_t now = time(0);
            char* dt = ctime(&now);
            string s(dt);
            if (!s.empty() && s.back() == '\n')
            s.pop_back();
            return s;
        }
};
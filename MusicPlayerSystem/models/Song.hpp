#pragma once 

#include<bits/stdc++.h>
using namespace std;

class Song 
{
    private:
        string title;
        string artist;
        string filePath;
    public:
        Song(string title, string artist, string path)
        {
            this->title = title;
            this->artist = artist;
            this->filePath = path;
        }
        string getTitle() const 
        {
            return title;
        }
        string getArtist() const 
        {
            return artist;
        }
        string getFilePath() const 
        {
            return filePath;
        }
};
#pragma once 

#include<bits/stdc++.h>
#include<Song.hpp>
using namespace std;

class Playlist 
{
    private:
        string playlistName;
        vector<Song*>songList;
    
    public:
        Playlist(string playlistName)
        {
            this->playlistName = playlistName;
        }
        string getPlaylistName()
        {
            return playlistName;
        }
        const vector<Song*>& getSongs()
        {
            return songList;
        }
        int getSize()
        {
            return songList.size();
        }
        void addSongToPlaylist(Song* song)
        {
            if(song == nullptr)
            {
                throw runtime_error("Cannot add null song to playlist.");
            }
            songList.push_back(song);
        }
};

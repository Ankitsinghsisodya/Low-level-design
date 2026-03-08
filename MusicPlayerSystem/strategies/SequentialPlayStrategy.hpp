#pragma once

#include <bits/stdc++.h>
#include <Playlist.hpp>
#include <PlayStrategy.hpp>
#include <Song.hpp>
using namespace std;

class SequentialPlayStrategy : public PlayStrategy
{
private:
    Playlist *currentPlaylist;
    int currentIndex;

public:
    SequentialPlayStrategy()
    {
        currentPlaylist = nullptr;
        currentIndex = -1;
    }
    void setPlaylist(Playlist *playlist) override
    {
        currentPlaylist = playlist;
        currentIndex = -1;
    }
    Song *next() override
    {
        if (!currentPlaylist || currentPlaylist->getSize() == 0)
        {
            throw runtime_error("No playlist loaded or playlist is empty.");
        }
        currentIndex++;
        return currentPlaylist->getSongs()[currentIndex];
    }

    bool hasNext() override
    {
        return ((currentIndex + 1) < currentPlaylist->getSize());
    }

    Song *previous() override
    {
        if (!currentPlaylist || currentPlaylist->getSize() == 0)
        {
            throw runtime_error("No playlist loaded or playlist is empty.");
        }
        currentIndex = currentIndex - 1;
        return currentPlaylist->getSongs()[currentIndex];
    }
    bool hasPrevious() override
    {
        return currentIndex - 1 >= 0;
    }
};

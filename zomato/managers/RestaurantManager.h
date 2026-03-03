#pragma once

#include<bits/stdc++.h>
#include<Restaurant.h>
using namespace std;

class RestaurantManager{
    private:
        vector<Restaurant *>restaurant;
        static RestaurantManager* instance;
        RestaurantManager(){

        }

    public:
    static RestaurantManager* getInstance(){
        if(!instance){
            instance = new RestaurantManager();
        }
        return instance;
    }
    void addRestaurant(Restaurant *r)
    {
        restaurant.push_back(r);
    }

    vector<Restaurant*> searchByLocation(const string &location)
    {
        vector<Restaurant*> result;
        transform(location.begin(), location.end(), location.begin(), ::tolower);
        for(auto r : restaurant)
        {
            string rl = r->getLocation();
            transform(rl.begin(), rl.end(), rl.begin(), ::tolower);
            if(rl == location)
                result.push_back(r);
        }
        return result;
    }
};

RestaurantManager* RestaurantManager::instance = nullptr;
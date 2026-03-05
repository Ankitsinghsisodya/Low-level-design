#pragma once 

#include<bits/stdc++.h>
using namespace std;
#include<Restaurant.h>
#include<MenuItem.h>

class Cart{
    private:
        Restaurant* restaurant;
        vector<MenuItem>items;
    
    public:
        Cart()
        {
            restaurant = nullptr;
        }

        void addItem(MenuItem item)
        {
            if(!restaurant)
            {
                cout << "Set restaurant before adding items\n";
                return;
            }
            items.push_back(item);
        }
        double getTotalCost() const
        {
            double sum = 0;
            for(const auto& item: items)
                sum += item.getPrice();
            return sum;
        }
        bool isEmpty() const{
            return !restaurant || items.empty();
        }
        void clear()
        {
            items.clear();
            restaurant = nullptr;
        }
        void setRestaurants(Restaurant* r)
        {
            restaurant = r;
        }
        Restaurant* getRestaurant() const
        {
            return restaurant;
        }
        const vector<MenuItem>& getItems() const 
        {
            return items;
        }

};
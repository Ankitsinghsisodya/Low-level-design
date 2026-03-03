#ifndef RESTAURANT.H 
#define RESTAURANT.H 

#include<bits/stdc++.h>
#include<MenuItem.h>
using namespace std;

class Restaurant{
    private:
        static int nextRestaurantId;
        int restaurantId;
        string name;
        string location;
        vector<MenuItem>menuItems;
    public:
        Restaurant(const string &name, const string location){
            this->name=name;
            this->location=location;
            this->restaurantId=nextRestaurantId++;
        }

        ~Restaurant(){
            cout << "Destroying the Restaurant and clearing the menu\n";
            menuItems.clear();
        }

        string getName() const
        {
            return name;
        }

        void setName(const string &name)
        {
            this->name = name;
        }

        string getLocation() const 
        {
            return location;
        }

        void setLocation(const string &location) 
        {
            this->location = location;
        }

        void addMenu(const MenuItem &item)
        {
            menuItems.push_back(item);
        }

        const vector<MenuItem>& getMenuItems() const 
        {
            return menuItems;
        }

};

int Restaurant::nextRestaurantId = 0;

#endif 
#pragma once 

#include<bits/stdc++.h>
using namespace std;
#include<Cart.h>


class User
{
    private:
        int userId;
        string name;
        string address;
        Cart* cart;
    
    public:
        User(int userId, const string& name, const string& address)
        {
            this->userId = userId;
            this->name = name;
            this->address = address;
            this->cart = new Cart();
        }
        ~User()
        {
            delete cart;
        }
        string getName() const
        {
            return name;
        }
        void setName(const string &name)
        {
            this->name = name;
        }
        string getAddress() const 
        {
            return address;
        }
        void updateAddress(const string &address)
        {
            this->address = address;
        }
        Cart* getCart() const 
        {
            return cart;
        }
};
#pragma once

#include<bits/stdc++.h>
using namespace std;
#include<User.h>
#include<Cart.h>
#include<Order.h>
#include<MenuItem.h>
#include<PaymentStrategy.h>

class OrderFactory
{
    public:
        virtual Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, const vector<MenuItem>& menuItems,
                                    PaymentStrategy *paymentStrategy, double totalCost, const string& orderType) = 0;
        virtual ~OrderFactory(){} 
};
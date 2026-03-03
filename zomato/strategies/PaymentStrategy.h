#pragma once 

#include<bits/stdc++.h>
using namespace std;

class PaymentStrategy{
    public:
        virtual void pay(double amount) = 0;
        virtual ~PaymentStrategy() {}
};
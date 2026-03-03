#pragma once 

#include<bits/stdc++.h>
#include<PaymentStrategy.h>
using namespace std;

class UpiPaymentStrategy: public PaymentStrategy {
    private:
        string mobileNumber;
    public:
    UpiPaymentStrategy(const string &mobileNumber){
        this->mobileNumber = mobileNumber;
    }
    void pay(double amount) override {
         cout << "Paid ₹" << amount << " using UPI (" << mobileNumber << ")" << endl;
    }
};
#pragma once 

#include<bits/stdc++.h>
#include<PaymentStrategy.h>

class CreditCardPaymentStrategy: public PaymentStrategy{
    private:
        string cardNumber;
    public:
        CreditCardPaymentStrategy(const string &cardNumber){
            this->cardNumber = cardNumber;
        }

        void pay(double amount) override {
             cout << "Paid ₹" << amount << " using Credit Card (" << cardNumber << ")" << endl;
        }
};
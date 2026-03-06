#pragma once
#include <iostream>
#include "INotificationStrategy.h"
using namespace std;

class SMSStrategy : public INotificationStrategy
{
private:
    string mobileNumber;

public:
    SMSStrategy(string mobileNumber) : mobileNumber(mobileNumber) {}

    void sendNotification(string content) override
    {
        cout << "Sending SMS Notification to: " << mobileNumber << "\n"
             << content;
    }
};

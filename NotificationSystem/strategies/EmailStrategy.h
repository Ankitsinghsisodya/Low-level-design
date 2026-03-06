#pragma once
#include <iostream>
#include "INotificationStrategy.h"
using namespace std;

class EmailStrategy : public INotificationStrategy
{
private:
    string emailId;

public:
    EmailStrategy(string emailId) : emailId(emailId) {}

    void sendNotification(string content) override
    {
        cout << "Sending email Notification to: " << emailId << "\n"
             << content;
    }
};

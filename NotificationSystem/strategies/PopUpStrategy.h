#pragma once
#include <iostream>
#include "INotificationStrategy.h"
using namespace std;

class PopUpStrategy : public INotificationStrategy
{
public:
    void sendNotification(string content) override
    {
        cout << "Sending Popup Notification: \n"
             << content;
    }
};

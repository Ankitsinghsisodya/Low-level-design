#pragma once
#include <iostream>
#include "IObserver.h"
#include "NotificationObservable.h"
using namespace std;

class Logger : public IObserver
{
private:
    NotificationObservable *notificationObservable;

public:
    Logger(NotificationObservable *observable) : notificationObservable(observable) {}

    void update() override
    {
        cout << "Logging New Notification : \n"
             << notificationObservable->getNotificationContent();
    }
};

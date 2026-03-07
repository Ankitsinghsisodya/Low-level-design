#pragma once
#include <iostream>
#include "IObserver.h"
#include "NotificationObservable.h"
#include "../services/NotificationService.h"
using namespace std;

class Logger : public IObserver
{
private:
    NotificationObservable *notificationObservable;

public:
    Logger()
    {
        this->notificationObservable = NotificationService::getInstance()->getObservable();
        notificationObservable->addObserver(this);
    }
    Logger(NotificationObservable *observable) : notificationObservable(observable) {}

    void update() override
    {
        cout << "Logging New Notification : \n"
             << notificationObservable->getNotificationContent();
    }
};

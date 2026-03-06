#pragma once
#include <iostream>
#include <vector>
#include "IObserver.h"
#include "NotificationObservable.h"
#include "../strategies/INotificationStrategy.h"
#include<NotificationService.h>
using namespace std;

class NotificationEngine : public IObserver
{
private:
    NotificationObservable *notificationObservable;
    vector<INotificationStrategy *> notificationStrategies;

public:
    NotificationEngine()
    {
        this->notificationObservable = NotificationService::getInstance()->getObservable();
        notificationObservable->addObserver(this);
    }
    NotificationEngine(NotificationObservable *observable) : notificationObservable(observable) {}

    void addNotificationStrategy(INotificationStrategy *ns)
    {
        notificationStrategies.push_back(ns);
    }

    void update() override
    {
        string content = notificationObservable->getNotificationContent();
        for (auto strategy : notificationStrategies)
            strategy->sendNotification(content);
    }
};

#pragma once
#include <vector>
#include "../models/INotification.h"
#include "../observers/NotificationObservable.h"
using namespace std;

class NotificationService
{
private:
    NotificationObservable *observable;
    static NotificationService *instance;
    vector<INotification *> notifications;

    NotificationService() : observable(new NotificationObservable()) {}

public:
    static NotificationService *getInstance()
    {
        if (instance == nullptr)
            instance = new NotificationService();
        return instance;
    }

    NotificationObservable *getObservable()
    {
        return observable;
    }

    void sendNotification(INotification *notification)
    {
        notifications.push_back(notification);
        observable->setNotification(notification);
    }

    ~NotificationService()
    {
        delete observable;
    }
};

NotificationService *NotificationService::instance = nullptr;

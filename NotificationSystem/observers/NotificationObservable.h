#pragma once
#include <vector>
#include <algorithm>
#include "IObservable.h"
#include "../models/INotification.h"
using namespace std;

class NotificationObservable : public IObservable
{
private:
    vector<IObserver *> observers;
    INotification *currentNotification;

public:
    NotificationObservable() : currentNotification(nullptr) {}

    void addObserver(IObserver *obs) override
    {
        observers.push_back(obs);
    }

    void removeObserver(IObserver *obs) override
    {
        observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
    }

    void notifyObservers() override
    {
        for (auto obs : observers)
            obs->update();
    }

    void setNotification(INotification *notification)
    {
        if (currentNotification != nullptr)
            delete currentNotification;
        currentNotification = notification;
        notifyObservers();
    }

    INotification *getNotification()
    {
        return currentNotification;
    }

    string getNotificationContent()
    {
        return currentNotification->getContent();
    }

    ~NotificationObservable()
    {
        if (currentNotification != nullptr)
            delete currentNotification;
    }
};

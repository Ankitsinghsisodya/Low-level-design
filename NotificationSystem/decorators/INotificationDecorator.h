#pragma once
#include "../models/INotification.h"

class INotificationDecorator : public INotification
{
protected:
    INotification *notification;

public:
    INotificationDecorator(INotification *n) : notification(n) {}

    virtual ~INotificationDecorator()
    {
        delete notification;
    }
};

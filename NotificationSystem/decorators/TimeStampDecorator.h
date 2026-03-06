#pragma once
#include "INotificationDecorator.h"
#include <string>
using namespace std;

class TimeStampDecorator : public INotificationDecorator
{
public:
    TimeStampDecorator(INotification *n) : INotificationDecorator(n) {}

    string getContent() const override
    {
        return "[2025-04-13 14:22:00] " + notification->getContent();
    }
};

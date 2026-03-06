#pragma once
#include <string>
using namespace std;

class INotificationStrategy
{
public:
    virtual void sendNotification(string content) = 0;
    virtual ~INotificationStrategy() {}
};

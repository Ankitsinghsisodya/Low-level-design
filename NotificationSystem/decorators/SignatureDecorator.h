#pragma once
#include "INotificationDecorator.h"
#include <string>
using namespace std;

class SignatureDecorator : public INotificationDecorator
{
private:
    string signature;

public:
    SignatureDecorator(INotification *n, const string &sig)
        : INotificationDecorator(n), signature(sig) {}

    string getContent() const override
    {
        return notification->getContent() + "\n-- " + signature + "\n\n";
    }
};

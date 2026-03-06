#pragma once
#include "INotification.h"
#include <string>
using namespace std;

class SimpleNotification : public INotification
{
private:
    string text;

public:
    SimpleNotification(const string &msg) : text(msg) {}

    string getContent() const override
    {
        return text;
    }
};

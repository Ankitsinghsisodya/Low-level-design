#pragma once
#include <string>
using namespace std;

class INotification
{
public:
    virtual string getContent() const = 0;
    virtual ~INotification() {}
};

#pragma once
#include "IObserver.h"

class IObservable
{
public:
    virtual void addObserver(IObserver *observer) = 0;
    virtual void removeObserver(IObserver *observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~IObservable() {}
};

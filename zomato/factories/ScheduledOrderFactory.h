#pragma once

#include <bits/stdc++.h>
#include <OrderFactory.h>
#include <DeliveryOrder.h>
#include <PickupOrder.h>
#include <TimeUtils.h>
using namespace std;

class ScheduledOrderFactory : public OrderFactory
{
private:
    string scheduledTime;

public:
    ScheduledOrderFactory(string scheduledTime)
    {
        this->scheduledTime = scheduledTime;
    }
    Order *createOrder(User *user, Cart *cart, Restaurant *restaurant, const vector<MenuItem> &menuItems,
                       PaymentStrategy *paymentStrategy, double totalCost, const string &orderType) override
    {
        Order *order = nullptr;

        if (orderType == "Delivery")
        {
            auto deliveryOrder = new DeliveryOrder();
            deliveryOrder->setUserAddress(user->getAddress());
            order = deliveryOrder;
        }
        else
        {
            auto pickupOrder = new PickupOrder();
            pickupOrder->setRestaurantAddress(restaurant->getLocation());
        }
        order->setUser(user);
        order->setRestaurant(restaurant);
        order->setItems(menuItems);
        order->setPaymentStrategy(paymentStrategy);
        order->setScheduled(scheduledTime);
        order->setTotal(totalCost);
        return order;
    }
};
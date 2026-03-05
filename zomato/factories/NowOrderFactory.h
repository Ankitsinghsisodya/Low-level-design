#pragma once 

#include<bits/stdc++.h>
#include<Order.h>
#include<TimeUtils.h>
#include<PickupOrder.h>
#include<DeliveryOrder.h>
#include<OrderFactory.h>
using namespace std;

class NowOrderFactory : public OrderFactory 
{
    public:
        Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, const vector<MenuItem>&menuItems, 
                            PaymentStrategy* paymentStrategy, double totalCost, const string& orderType){
                Order* order = nullptr;
                if(orderType == "Delivery")
                {
                    auto deliveryOrder = new DeliveryOrder();
                    deliveryOrder->setUserAddress(user->getAddress());
                    order = deliveryOrder;
                }
                else
                {
                    auto pickupOrder = new PickupOrder();
                    pickupOrder->setRestaurantAddress(restaurant->getLocation());
                    order = pickupOrder;
                }
                order->setUser(user);
                order->setRestaurant(restaurant);
                order->setItems(menuItems);
                order->setPaymentStrategy(paymentStrategy);
                order->setScheduled(TimeUtils::getCurrentTime());
                order->setTotal(totalCost);
                return order;
        }
};
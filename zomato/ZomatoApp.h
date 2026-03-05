#pragma once

#include <bits/stdc++.h>
#include <User.h>
#include <Restaurant.h>
#include <Cart.h>
#include <RestaurantManager.h>
#include <OrderManager.h>
#include <PaymentStrategy.h>
#include <UpiPaymentStrategy.h>
#include <NowOrderFactory.h>
#include <ScheduledOrderFactory.h>
#include <NotificationService.h>
#include <TimeUtils.h>
#include <MenuItem.h>

using namespace std;

class ZomatoApp
{
public:
    ZomatoApp()
    {
        initializeRestaurants();
    }

    void initializeRestaurants()
    {
        Restaurant *restaurant1 = new Restaurant("Bikaner", "Delhi");
        restaurant1->addMenu(MenuItem(1, 120, "Chole Bhature"));
        restaurant1->addMenu(MenuItem(2, 15, "Samosa"));

        Restaurant *restaurant2 = new Restaurant("Haldiram", "Kolkata");
        restaurant2->addMenu(MenuItem(1, 80, "Raj Kachori"));
        restaurant2->addMenu(MenuItem(2, 100, "Pav Bhaji"));
        restaurant2->addMenu(MenuItem(3, 50, "Dhokla"));

        Restaurant *restaurant3 = new Restaurant("Saravana Bhavan", "Chennai");
        restaurant3->addMenu(MenuItem(1, 90, "Masala Dosa"));
        restaurant3->addMenu(MenuItem(2, 60, "Idli Vada"));
        restaurant3->addMenu(MenuItem(3, 30, "Filter Coffee"));

        RestaurantManager *restaurantManager = RestaurantManager::getInstance();
        restaurantManager->addRestaurant(restaurant1);
        restaurantManager->addRestaurant(restaurant2);
        restaurantManager->addRestaurant(restaurant3);
    }

    vector<Restaurant*> searchRestaurants(const string& location) {
        return RestaurantManager::getInstance()->searchByLocation(location);
    }

     void selectRestaurant(User* user, Restaurant* restaurant) {
        Cart* cart = user->getCart();
        cart->setRestaurants(restaurant);
    }

    void addToCart(User* user, const int itemCode) {
        Restaurant* restaurant = user->getCart()->getRestaurant();
        if (!restaurant) {
            cout << "Please select a restaurant first." << endl;
            return;
        }
        for (const auto& item : restaurant->getMenuItems()) {
            if (item.getCode() == itemCode) {
                user->getCart()->addItem(item);
                break;
            }
        }
    }

    Order* checkoutNow(User* user, const string& orderType, PaymentStrategy* paymentStrategy) {
        return checkout(user, orderType, paymentStrategy, new NowOrderFactory());
    }

    Order* checkoutScheduled(User* user, const string& orderType, PaymentStrategy* paymentStrategy, const string& scheduleTime) {
        return checkout(user, orderType, paymentStrategy, new ScheduledOrderFactory(scheduleTime));
    }

    Order* checkout(User* user, const string& orderType, 
        PaymentStrategy* paymentStrategy, OrderFactory* orderFactory) {
        if (user->getCart()->isEmpty())
        return nullptr;

        Cart* userCart = user->getCart();
        Restaurant* orderedRestaurant = userCart->getRestaurant();
        vector<MenuItem> itemsOrdered = userCart->getItems();
        double totalCost = userCart->getTotalCost();

        Order* order = orderFactory->createOrder(user, userCart, orderedRestaurant, itemsOrdered, paymentStrategy, totalCost, orderType);
        OrderManager::getInstance()->addOrder(order);
        return order;
    }

    void payForOrder(User* user, Order* order) {
        bool isPaymentSuccess = order->processPayment();

        // clear user cart if payment is successful.
        if(isPaymentSuccess) {
            NotificatoinService* notification = new NotificatoinService();
            notification->notify(order);
            user->getCart()->clear();
        }  
    }

    void printUserCart(User* user) {
        cout << "Items in cart:" << endl;
        cout << "------------------------------------" << endl;
        for (const auto& item : user->getCart()->getItems()) {
            cout << item.getCode() << " : " << item.getItemName() << " : ₹" << item.getPrice() << endl;
        }
        cout << "------------------------------------" << endl;
        cout << "Grand total : ₹" << user->getCart()->getTotalCost() << endl;
    }

};
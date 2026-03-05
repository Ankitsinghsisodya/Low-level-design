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
};
#pragma once

#include <bits/stdc++.h>
using namespace std;
#include<Order.h>
#include<MenuItem.h>

class NotificatoinService
{
public:
    static void notify(Order *order)
    {
        cout << "\nNotification: New " << order->getType() << " order placed!" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Order ID: " << order->getOrderId() << endl;
        cout << "Customer: " << order->getUser()->getName() << endl;
        cout << "Restaurant: " << order->getRestaurant()->getName() << endl;
        cout << "Items Ordered:\n";

        const vector<MenuItem> &items = order->getItems();
        for (const auto &item : items)
        {
            cout << "   - " << item.getItemName() << " (₹" << item.getPrice() << ")\n";
        }

        cout << "Total: ₹" << order->getTotal() << endl;
        cout << "Scheduled For: " << order->getScheduled() << endl;
        cout << "Payment: Done" << endl;
        cout << "---------------------------------------------" << endl;
    }
};

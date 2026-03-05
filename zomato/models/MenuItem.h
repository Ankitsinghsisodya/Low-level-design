#pragma once

#include <bits/stdc++.h>
using namespace std;

class MenuItem
{
private:
    int menuId, price;
    string itemName;

public:
    MenuItem(int menuId, int price, string itemName)
    {
        this->menuId = menuId;
        this->price = price;
        this->itemName = itemName;
    }

    void setMenuId(int menuId)
    {
        this->menuId = menuId;
    }
    int getMenuId() const
    {
        return menuId;
    }
    void setPrice(int price)
    {
        this->price = price;
    }
    double getPrice() const
    {
        return price;
    }
    void setIemName(string itemName)
    {
        this->itemName = itemName;
    }
    string getItemName() const
    {
        return itemName;
    }
};
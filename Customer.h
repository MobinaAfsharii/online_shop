#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>

using namespace std;
#pragma once
#include "Cart.h"
#include "Receipt.h"
class Customer
{
public:
    Customer();
    ~Customer();
    Customer(int, string , string , string , float);
    void convert_cart_to_receipt();
    float get_total_purchace_amount();
    Cart get_cart();
    void set_cart(Cart);
    int get_customer_id();
    Receipt get_customer_receipt(int);
    void save_cust();

protected:

    int id;
    string name;
    string phone_number;
    Receipt history[10];
    string address;
    Cart cart;
    float balance;
    int receipt=0;
};

#endif
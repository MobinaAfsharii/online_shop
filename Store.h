#ifndef STORE_H
#define STORE_H
#include <iostream>
#include <string>

using namespace std;
#pragma once
#include "Customer.h"
#include "Product.h"
#include "Stock.h"
#include "Date.h"
class Store
{
    
public:
    Store();
    ~Store();
    void check_out(Customer);
    void add_customer();
    void add_product();
    void view_products();
    void save_to_file();
    void sales_report(Date,Date);

//protected:
    Product products[5];
    Stock st;
    Customer customers[5];
    int size_of_customer=0;
    int size_of_product=0;
};

#endif
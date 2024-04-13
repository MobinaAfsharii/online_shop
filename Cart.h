#ifndef CART_H
#define CART_H
#include <iostream>
#include <string>

using namespace std;
#pragma once
#include <utility>
#include "Product.h"
#include "Stock.h"

class Cart:public Stock
{
    
public:

    void add(int,int);
    void remove_item(int);
    void print();
    void check_out();
    void reset();
    float get_total_price();
    //setter getter
    void set_id(int,int);
    void set_quantity(int,int);
    int get_id(int);
    int get_quantity(int);

protected:
    pair<int,int> items[5];
    pair<int,int> i_p[5];
    int size=0;
};

#endif
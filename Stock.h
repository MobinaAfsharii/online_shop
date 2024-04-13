#ifndef STOCK_H
#define STOCK_H
#include <iostream>
#include <string>
#include <utility>
using namespace std;

#pragma once

class Stock
{
    
public:
    //Stock();
    //~Stock();
    int get_count(int);
    void change_count_by(int ,int);
    void set_stock_id(int,int);
    void set_stock_stock(int,int);
    void set_stock_price(float,int);

protected:
    pair<int, int> stock[5];
    pair<int, float> id_price[5];


};

#endif
#ifndef RECEIPT_H
#define RECEIPT_H
#include <iostream>
#include <string>

using namespace std;
#pragma once
#include <utility>
#include "Date.h"

class Receipt
{
public:
    
    float get_total_price();
    void set_date(Date);
    void set_id(int,int);
    void set_quantity(int,int);
    int get_id(int);
    Date get_date();


//protected:
    pair<int,int> items[100];
    Date date;


};

#endif
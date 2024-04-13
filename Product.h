#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>
#include <utility>

using namespace std;
#pragma once
#include "Cart.h"
#include "Date.h"
//#include "Store.h"
class Product
{
    friend class cart;
public:
    Product();
    ~Product();
    Product(int ,string,float,string,Date);
    void set_product_id(int);
    int get_product_id();
    void set_product_name(string);
    string get_product_name();
    void set_product_price(float);
    float get_product_price();
    void set_product_brand(string);
    string get_product_brand();
    //void set_product_expire_date(Date);
    //Date get_product_expire_date();
    void save_to_file_pro();
    
protected:
    int id;
    string name;
    float price;
    string brand;
    Date expire_date;
    pair<int,int> id_price;
    
    

};

#endif
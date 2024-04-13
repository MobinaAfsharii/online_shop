#include "Product.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
Product::Product()
{

}

Product::~Product()
{

}
Product::Product(int i,string n,float p,string b,Date e)
{
    id=i;
    name=n;
    price=p;
    brand=b;
    expire_date.day=e.day;
    expire_date.month=e.month;
    expire_date.year=e.year;
    id_price.first=id;
    id_price.second=price;
    (*this).save_to_file_pro();
    
}
void Product::set_product_id(int i){id=i;}

int Product::get_product_id(){return id;}

void Product::set_product_name(string n){name=n;}

string Product::get_product_name(){return name;}
    
void Product::set_product_price(float p){price=p;}

float Product::get_product_price(){return price;}

void Product::set_product_brand(string b){brand=b;}
    
string Product::get_product_brand(){return brand;}
    
/*void Product::set_product_expire_date(Date d){expire_date=d;}

Date Product::get_product_expire_date(){expire_date.print(); return expire_date;}*/
void Product::save_to_file_pro()
{
    /*ofstream binFile("z.dat", ios::binary | ios::out | ios::in);
    binFile.write(reinterpret_cast<char*>(id_price), sizeof(id_price));
    binFile.close();*/
    ofstream wf("z.dat", ios::out | ios::binary);
    if(!wf) {
        cout << "Cannot open file!" << endl;
    }
    wf.write((char *) &id_price, sizeof(id_price));
}
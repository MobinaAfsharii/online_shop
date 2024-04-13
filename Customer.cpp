#include "Customer.h"
#include <iostream>
#include <string>
#include "Date.h"
#include <fstream>

using namespace std;
Customer::Customer()
{

}

Customer::~Customer()
{

}
Customer::Customer(int i, string n , string phone , string add ,float b)
{
    id=i;
    name=n;
    phone_number=phone;
    address=add;
    balance=b;
}
void Customer::convert_cart_to_receipt()
{
    receipt++;
    Customer t=(*this);
    Receipt a=t.history[receipt];
    Cart c=t.cart;
    int i=1;
    while(c.get_id(i))
    {
        a.set_id(c.get_id(i),i);
        a.set_quantity(c.get_quantity(i),i);
        i++;
    }
    balance-=c.get_total_price();
    cout<<c.get_total_price();
    c.reset();
    cout<<"enter date:"<<endl;
    Date d;
    int hello;
    cin>>hello;
    d.day=hello%100;
    hello/=100;
    d.month=hello%100;
    hello/=100;
    d.year=hello;
    history[receipt]=a;

}
float Customer::get_total_purchace_amount()
{
    float tt=0;
    for(int i=1;history[i].get_id(i);i++)
    {
        tt+=history[i].get_total_price();
    }
}
Cart Customer::get_cart()
{
    return (*this).cart;
}
void Customer::set_cart(Cart c)
{
    (*this).cart=c;
}
int Customer::get_customer_id()
{
    return id;
}
Receipt Customer::get_customer_receipt(int i)
{
    return history[i];
}
void Customer::save_cust()
{
    ofstream wf("A.dat", ios::out | ios::binary);
    if(!wf) {
        cout << "Cannot open file!" << endl;
    }
    for(int i=1;history[i].get_id(i);i++)
        wf.write((char *) &history[i], sizeof(history));
}
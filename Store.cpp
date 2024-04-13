#include "Store.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Customer.h"
#include "Stock.h"
#include"Cart.h"

using namespace std;

Store::Store()
{
    ifstream rf("z.dat", ios::out | ios::binary);
    
    products[1];
    rf.read(reinterpret_cast<char*>(&products), sizeof(products));
    for(int i=1;products[i].get_product_id();i++)
    {
        while(!rf.eof())
        {
            rf.read(reinterpret_cast<char*>(&products), sizeof(products));
        }
    }
    customers[1];
    rf.read(reinterpret_cast<char*>(&customers), sizeof(customers));
    for(int i=1;customers[i].get_customer_id();i++)
    {
        while(!rf.eof())
        {
            rf.read(reinterpret_cast<char*>(&customers), sizeof(customers));
        }
    }
    st;
    rf.read(reinterpret_cast<char*>(&st), sizeof(st));

    
}

Store::~Store()
{

}
void Store ::check_out(Customer a)
{
    Stock b;
    int i=1;
    while(a.get_cart().get_id(i))
    {
        b.change_count_by(a.get_cart().get_id(i) ,-(a.get_cart().get_quantity(i)));
        i++;
    }
    a.get_cart().check_out();
    a.convert_cart_to_receipt();
}
void Store::add_customer()
{
    Cart crt;
    float balance;
    int id;
    string name,phone_number,address;
    cout<<"Enter id:";
    cin >>id;
    cout<<"Enter name:";
    cin >> name;
    cout<<"Enter phone_number:";
    cin >>phone_number;
    cout<<"Enter address:";
    cin >>address;
    cout<<"Enter balance:";
    cin >>balance;
    Customer b=Customer(id,name,phone_number,address,balance);
    b.set_cart(crt);
    ++size_of_customer;
    customers[size_of_customer]=b;
    
}
void Store::add_product()
{
    Date date;
    int id , st,lon;
    float price;
    string name,brand;
    cout<<"Enter id:";
    cin >>id;
    cout<<"Enter name:";
    cin >> name;
    cout<<"Enter price:";
    cin >>price;
    cout<<"Enter brand:";
    cin >>brand;
    cout<<"Enter expire date:";
    cin >>lon;
    date.day=lon%100;
    lon/=100;
    date.month=lon%100;
    lon/=100;
    date.year=lon;
    cout<<"Enter stocks:";
    cin>>st;
    Product b=Product(id,name,price,brand,date);
    size_of_product++;
    products[size_of_product]=b;
    this->st.set_stock_id(id,size_of_product);
    this->st.set_stock_stock(st,size_of_product);

}
void Store::view_products()
{
    for(int i=1;i<=size_of_product;i++)
    {
        cout<<"id:";
        cout<<products[i].get_product_id()<<endl;
        cout<<"name:";
        cout<<products[i].get_product_name()<<endl;
        cout<<"price:";
        cout<<products[i].get_product_price()<<endl;
        cout<<"brand:";
        cout<<products[i].get_product_brand()<<endl;
        
    }
    
    
}
void Store::save_to_file()
{

    ofstream wf("saved.dat", ios::out | ios::binary);
    if(!wf) {
        cout << "Cannot open file!" << endl;
    }
    for(int i=1;products[i].get_product_id();i++)
    {    
        wf.write((char *) &products[i], sizeof(products));
    }
    for(int i=1;customers[i].get_customer_id();i++)
    {    
        wf.write((char *) &customers[i], sizeof(customers));
    }
    wf.write((char *) &st, sizeof(st));
}
void Store::sales_report(Date begin,Date end)
{
    
    ifstream rf("A.dat", ios::out | ios::binary);
    Receipt a;
    rf.read(reinterpret_cast<char*>(&a), sizeof(a));
    int mob=a.items[0].first;
    int gh=a.items[1].first;
    for(int i=0;a.items[i].first;i++)
    {
        float t=0;
        while(!rf.eof())
        {
            if(a.date.day==begin.day)
                if(a.date.month==begin.month)
                    if(a.date.year==begin.year)
                        t+=a.get_total_price();
            rf.read(reinterpret_cast<char*>(&a), sizeof(a));
        }
        cout<<begin.year<<" "<<begin.month<<" "<<begin.day<<":";
        int l=t/100;
        for(int j=0;j<l;j++)
        {
            cout<<"+";
        }
        if(begin.day<30)
            begin.day+=1;
        
    }
    rf.close();
    
}



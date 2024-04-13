#include <iostream>
#include <string>
#include "Product.cpp"
#include "Stock.cpp"
#include "Cart.cpp"
#include "Receipt.cpp"
#include "Customer.cpp"
#include "Store.cpp"
#include "Date.h"
using namespace std;
int main()
{
    /*Date m,n;
    m.day=5;
    m.month=6;
    m.year=2022;
    m.day=6;
    m.month=6;
    m.year=2022;
    cout<<"--------------product-----------------"<<endl;
    Product a(795,"name",20,"brand",m);
    cout<<a.get_product_id()<<endl;
    cout<<a.get_product_name()<<endl; 
    cout<<a.get_product_price()<<endl;
    cout<<a.get_product_brand()<<endl;
    a.save_to_file_pro();
    //a.get_product_expire_date();
    cout<<"--------------------Stock------------------"<<endl;
    Stock b;
    b.set_stock_id(45,1);
    b.set_stock_stock(5,1);
    b.change_count_by(45,7);
    cout<<b.get_count(45);
    cout<<endl<<"---------------------Cart-----------------"<<endl;
    Cart c; 
    c.add(45,1);
    c.add(78,2);
    c.print();
    c.remove_item(45);
    c.print();
    c.reset();
    c.add(795,5);
    c.add(794,8);
    c.print();
    cout<<c.get_total_price()<<endl;
    c.reset();
    cout<<c.get_total_price();
    Cart mine;
    mine.add(795,10);
    cout<<mine.get_total_price()<<endl;
    cout<<endl<<"--------------------Receipt--------------------"<<endl;
    Receipt d;
    d.set_id(85,1);
    d.set_quantity(5,1);
    cout<<d.get_id(1);
    d.get_total_price();
    cout<<endl<<"-------------------Customer--------------"<<endl;
    Customer e(56,"hey","09555","dfgf",1000000);
    cout<<e.get_customer_id()<<endl;
    e.get_cart();
    e.set_cart(c);
    e.get_customer_receipt(2);
    e.convert_cart_to_receipt();
    e.get_total_purchace_amount();
    e.save_cust();
    Customer you(6,"hey","09555","dfgf",1000000);
    you.set_cart(mine);
    you.convert_cart_to_receipt();
    you.get_total_purchace_amount();
    you.save_cust();
    cout<<endl<<"----------------Store----------------"<<endl;
    Store f;
    f.add_product();
    f.view_products();
    f.add_customer(); 
    f.check_out(e);
    f.save_to_file();
    super_market.sales_report(m,n);*/
    Store super_market;
    
    cout<<"add product:";

    super_market.add_product();
    super_market.add_product();
    super_market.add_product();

    cout<<"add customer:";
    super_market.add_customer();

    cout<<"view products";
    super_market.view_products();

    int id,quantity;
    cout<<"enter your choices id:";
    cin>>id;
    cout<<"how many :";
    cin>>quantity;
    
    super_market.customers[1].get_cart().add(id,quantity);

    int x;
    cout<<"do you want to delete or change anything?"
        <<endl<<"for deleting press 1 for buying press 2";
    cin>>x;
    if(x==1)
    {
        int d;
        cout<<"enter the product id:";
        cin>>d;
        super_market.customers[1].get_cart().remove_item(d);
    }
    if(x==2)
    {
        super_market.check_out(super_market.customers[1]);
    }
    super_market.customers[1].save_cust();
    cout<<"thank for chosing us"<<endl
        <<"for more detail change the main";
    




}
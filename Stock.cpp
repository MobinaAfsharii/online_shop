#include "Stock.h"
#include <iostream>
#include <string>

using namespace std;
/*Stock::Stock()
{

}

Stock::~Stock()
{

}*/
void Stock::change_count_by(int id,int st)
{
    int i=1;
    while(stock[i].first)
    {
        if(stock[i].first==id)
            stock[i].second+=st;
        i++;
    }

}
int Stock::get_count(int id)
{
    int i=1;
    while(stock[i].first)
    {
        if(stock[i].first==id)
            return stock[i].second;
    
        i++;
    }
}
void Stock::set_stock_id(int i,int count)
{
    stock[count].first=i;
}
void Stock::set_stock_stock(int s,int count)
{
    stock[count].second=s;
}
void Stock::set_stock_price(float p,int count)
{
    id_price[count].first = stock[count].first;
    id_price[count].second = p;
}

#include "Cart.h"
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;

void Cart:: add(int id,int stock)
{
    ++size;
    items[size].first=id;
    items[size].second=stock;

}
void Cart::remove_item(int id)
{
    int b;
    int i=1;
    while(items[i].first)
    {
        if (items[i].first==id)
            b=i;
        i++;
    }
    for(int j=b;j<i;j++)
    {
        items[j]=items[j+1];
    }
    items[i-2].first='\0';
    --size;

}
void Cart::print()
{
    int i=1;
    while(items[i].first)
    {
        cout<<"id:"<<items[i].first<<endl
            <<"quantity:"<<items[i].second<<endl;
        i++;
    }

}
void Cart::reset()
{
    int i=1;
    while(items[i].first)
    {
        items[i].first='\0';
        i++;
        --size;
    }
    size=0;

}

void Cart::check_out()
{
    int i=1,j=1;
    while(items[i].first)
    {
        if(items[i].first==(*this).stock[j].first)
        {
            if((*this).stock[j].second<=0)
            {
                throw runtime_error("finished!!");
            }
            j++;
        }  
        i++;
    }
}
float Cart::get_total_price()
{
    float t=0;

    ifstream rf("z.dat", ios::out | ios::binary);
    pair<int,int> i_p;
    rf.read(reinterpret_cast<char*>(&i_p), sizeof(i_p));
    for(int i=1;items[i].first;i++)
    {
        while(!rf.eof())
        {
            if(i_p.first==items[i].first)
                t+=(i_p.second)*items[i].second;
            rf.read(reinterpret_cast<char*>(&i_p), sizeof(i_p));
            i++;
        }
    }
    rf.close();
    return t;
}
void Cart::set_id(int i,int count)
{
    (*this).items[count].first=i;
}
void Cart::set_quantity(int i,int count)
{
    (*this).items[count].second=i;
}
int Cart::get_id(int i)
{
    return (*this).items[i].first; 
}
int Cart::get_quantity(int i)
{
    return (*this).items[i].second;
}
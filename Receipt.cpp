#include "Receipt.h"
#include <fstream>
#include <utility>
/*Receipt::Receipt()
{

}

Receipt::~Receipt()
{

}*/
float Receipt::get_total_price()
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
void Receipt::set_id(int i,int count)
{
    (*this).items[count].first=i;
}
void Receipt::set_date(Date d)
{
    (*this).date=d;
}
void Receipt::set_quantity(int i,int count)
{
    (*this).items[count].second=i;
}
int Receipt::get_id(int i)
{
    return (*this).items[i].first; 
}
Date Receipt::get_date()
{
    return (*this).date;
}
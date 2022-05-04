#pragma
#include <iostream>
using namespace std;

struct charArr
{
    char a[];
    charArr(){};
    charArr( std::string a_)
    {
        for (int i =0 ; i < sizeof(a_); i++)
        {
            a[i] = a_[i];
        }
    }
};

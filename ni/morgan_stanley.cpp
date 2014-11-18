/*
 * =====================================================================================
 *
 *       Filename:  morgan_stanley.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 16 November 2014 02:03:20  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map <  int , int > H;

int calculate_max_exchange( int init_value )
{
    int n = init_value;
    if(!H[n])
        H[n] = ( n < n/2 + n/3 + n/4 ) ? calculate_max_exchange(n/2) + calculate_max_exchange(n/3) + calculate_max_exchange(n/4) : n;
    return H[n];
}

int main()
{

    int n;

    while( scanf("%d",&n) != EOF)
    {
        printf("%u\n",calculate_max_exchange(n));
    }

    return 0;

}


/*
 * =====================================================================================
 *
 *       Filename:  sansa_xor.cpp
 *
 *    Description:  https://www.hackerrank.com/contests/w9/challenges/sansa-and-xor
 *
 *        Version:  1.0
 *        Created:  Thursday 28 August 2014 02:16:45  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ajeet Jha (), ajeetjha1@gmail.com
 *   Organization:  Zi-eel
 *         Status:  Unsolved
 *
 * =====================================================================================
 */

/*
 * Logic:
 * counting occurence of all integers in the contiguous subsequences.
 * say, there are N integers.
 * min-element and max-element will occur N times.
 * and rest all elements will occur N+1 times.
 */

#include<iostream>
#include<limits>
using namespace std;


int main() {
    int t ;
    cin>>t;
    while (t--) {
        int res = 0;
        int n;
        cin >>n;
        int _min = numeric_limits<int>::max();
        int _max = numeric_limits<int>::min();
        for (int i = 0 ; i<n ; i++){
            int x;
            cin>>x;
            if (x <_min)
                    _min = x;
            if (x > _max)
                    _max = x;
            if ( ((n+1)%2) == 1)
                res = res^x;
        }
        res = res ^ _min;
        res = res ^ _max;
        cout<<res<<endl;
        
    }
}

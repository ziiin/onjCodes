/*
 * =====================================================================================
 *
 *       Filename:  service_lane.cpp
 *
 *    Description:  https://www.hackerrank.com/challenges/the-love-letter-mystery
 *
 *        Version:  1.0
 *        Created:  Wednesday 20 August 2014 11:45:58  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ajeet Jha, ajeetjha1@gmail.com
 *   Organization:  Zi-eel
 *
 * =====================================================================================
 */

#include<iostream>
#include<cmath>

using namespace std;

int main() {
        int t;
        cin>>t;
        while (t--){
                string s;
                cin>>s;
                int len = s.size();
                int res = 0;
                int mirror_i;
                for (int i = 0; i < len/2 ; i++) {
                        mirror_i = len - i - 1;
                        res += abs(s[i] - s[mirror_i]);
                }
                cout<<res<<endl;
        }
}


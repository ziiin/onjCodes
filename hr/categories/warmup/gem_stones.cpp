/*
 * =====================================================================================
 *
 *       Filename:  gem_stones.cpp
 *
 *    Description:  https://www.hackerrank.com/challenges/gem-stones
 *
 *        Version:  1.0
 *        Created:  Wednesday 20 August 2014 02:27:38  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ajeet Jha, ajeetjha1@gmail.com
 *   Organization:  Zi-eel
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
        int t;
        cin>>t;
        int gem[26] = {0,};
        for (int test = 0 ; test <t; test++) {
                string str;
                cin>>str;
                transform (str.begin(), str.end(), str.begin(), ::tolower);
                sort (str.begin(),str.end());
                for (int i = 0 ; i<str.size() -1 ; i++){
                        if (str[i] == str[i+1]) {
                                continue;
                        }
                        gem[str[i]-'a']++;
                }
                gem[str[str.size()-1]-'a']++;

        }
        int res = 0;
        for ( int i = 0 ; i<26; i++) {
                if (gem[i] == t)
                        res++;
                //cout <<gem[i]<<" ";
        }
        cout<<res<<endl;
} 


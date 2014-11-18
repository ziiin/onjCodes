/*
 * =====================================================================================
 *
 *       Filename:  morgan_stanley1.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 16 November 2014 02:03:54  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */
#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<cstdbool>
#include<cstdio>
#include<algorithm>
using namespace std;

map<string, int> M;
void init(){
        M["Jan"] = 1; M["Feb"] = 2; M["Mar"] = 3; M["Apr"] = 4;
        M["May"] = 5; M["Jun"] = 6; M["Jul"] = 7; M["Aug"] = 8;
        M["Sep"] = 9; M["Oct"] = 10; M["Nov"] = 11; M["Dec"] = 12;
}

bool mySort( string s1, string s2) {
        int day1, year1;
        int day2, year2;
        char month1[5], month2[5];
        sscanf(s1.c_str(),"%d %s %d",&day1, month1, &year1);
        sscanf(s2.c_str(),"%d %s %d",&day2, month2, &year2);
        //cout<<day1<<month1<<year1;
        string m1 (month1), m2(month2);
        int mon1 = M[m1] , mon2 = M[m2];
        //cout<<day1<<month1<<m1<<mon1<<year1<<endl;
        //cout<<day2<<month2<<m2<<mon2<<year2;

        if (year1== year2 && mon1 == mon2)
                return day1<day2;
        else if( year1 == year2)
                return mon1<mon2;
        else
                return year1<year2;

        

}

string get_earliest_dates (vector<string> dates) {
        static int s = 0;
        if (s==0) {
                init();
                s++;
        }
        sort(dates.begin(), dates.end(), mySort);
        return dates[0];
}

int main(){
        //map<string, int> M;
         
       vector<string> v;
      v.push_back("2 Jan 2013") ;
      v.push_back("14 Mar 2011");
      cout<< get_earliest_dates(v);
}


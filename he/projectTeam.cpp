/*
 * =====================================================================================
 *
 *       Filename:  projectTeam.cpp
 *
 *    Description:  http://www.hackerearth.com/problem/algorithm/project-team/description/
 *
 *        Version:  1.0
 *        Created:  Monday 24 November 2014 07:53:22  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ajeet Jha (), ajha@redhat.com
 *   Organization:  RedHat
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
        int t;
        cin>>t;
        
        while (t--) {
                int n;
                cin>>n;
               
               cout<<"T!"<<endl; 
                vector<int> v, sums;
                cout<<"T#"<<endl;
                for (int i; i <n ; i++) {
                        cout<<"Test1"<<endl;
                        int x;
                        cin>>x;
                        v.push_back(x);
                }
                
                sort(v.begin(), v.end());
                
                int last_sum = 0;
                int min_diff = v[n-1] + v[0];
                // 0 1 2 3 (4)
                for (int right = n/2; right<n ; right++ ) {
                        int left  = n - (right+1);
                        /*
                        int tmp_diff = abs(last_sum - (v[right] + v[left]));
                        
                        if (tmp_diff < min_diff)
                                min_diff = tmp_diff;
                         */
                         last_sum = (v[right] + v[left]);
                         cout<<"last sum: "<<last_sum<<" "<<right<< " "<<v[right]<<" "<<left<<" "<<v[left]<<endl;
                         
                         sums.push_back(last_sum);
                         
                }
                
                int n1 = sums.size();
                sort(sums.begin(), sums.end());
                min_diff = sums.back() - sums[0];
                cout<<min_diff<<endl;
                
        }
        
    //cout << "Hello World!" << endl;
    return 0;
}


#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector <vector <int> > threeSum (vector<int> vi) {
        vector <vector<int> > vv;

        int a,b,c;
        for (int i = 0 ; i<vi.size() ; i++) {
                a = vi[i];

                int j =  i+1;
                int k = vi.size() -1;

                while (k>j) {
                        b = vi[j];
                        c = vi[k];
                        if (a+b+c == 0 ) {
                                vector<int> tv(3);
                                tv[0] = a;
                                tv[1] = b;
                                tv[2] = c;
                                vv.push_back(tv);
                        }
                        if (a+b+c > 0)
                                k--;
                        else 
                                j++;
                }

        }
        return vv;
}

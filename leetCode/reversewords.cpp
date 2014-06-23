/*
 * =====================================================================================
 *
 *       Filename:  reversewords.cpp
 *
 *    Description:  Reverse words for a given sentence
 *    https://oj.leetcode.com/problems/reverse-words-in-a-string/
 *
 *        Version:  1.0
 *        Created:  09/06/14 15:36:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ajeet Jha (), ajha@redhat.com
 *   Organization:  RedHat
 *
 * =====================================================================================
 */

#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>

using namespace std;

void
iterate_white_front (string str, int *i) {
        while(  ((*i) < str.length()) && !(isalnum(str[*i]) ) ) {
                        (*i)++; 
                        }
}

void
iterate_white_back (string str, int *i) {
        while( ((*i) >=0)  && !(isalnum(str[*i]) ) ) {
                (*i)--;
        }
}

void
iterate_alnum_front (string str, int *i) {
        while( (  ((*i) < str.length()) && isalnum(str[*i]) ) ) {
                (*i)++;
        }
}

int
iterate (string &str, int *i1, string &s1, int *i2, string &s2) {
        // start from i1
        int i;
        s1 = "";
        for ( i = *i1 ; i< str.length() ; i++) {
                if ( isalnum (str[i]) )
                        s1 = s1 + str[i];
                else
                        break;
        }
        
        s2 = "";
        for ( i =  *i2 ; i >=0 ; i--) {
                if (isalnum (str[i]) )
                        s2 = s2 + str[i];
                else
                        break;
        }
        *i2 = i+1;
        reverse (s2.begin(), s2.end());
        // check if its a chracter, iterate till u reach a non-character
        // start from i2 
        // iterate backwards  till you hit a non-character
        // check if i2 is not ahead of i1
        cout<<"Iterate : "<<*i1 <<": "<<s1<<" ## "<<*i2<< ": "<<s2<<endl;
}

void
swap (string &str, int *i1, string &s1, int *i2, string &s2 ) {
        // take out string s2 from i2 insert s1
        str.erase (*i2, s2.length() );
        str.insert (*i2, s1);
        str.erase (*i1, s1.length() );
        str.insert (*i1, s2);
        *i2 = (*i2) - ( s1.length() - s2.length());
        // take off s1 from i1 and insert s2
}
void reversewords (string &s) {
        string tmp1;
        string tmp2;

        int i1, i2;
        i1 = 0;
        i2 = s.length()-1;
        if (i1 >= i2)
                return;
        iterate_white_front (s, &i1);
        iterate_white_back (s, &i2);
        while(i1 < i2){
                iterate_white_front (s, &i1);
                iterate_white_back (s, &i2);
                iterate (s, &i1, tmp1, &i2, tmp2);
                if (i1 < i2){
                        cout <<"swapping : "<<"#"<<tmp1<<"#"<<"  -> "<<"#"<<tmp2<<"#"<<endl;
                        swap (s, &i1, tmp1, &i2, tmp2);
                }
                else
                        break;
                //swap (s, &i1, tmp1, &i2, tmp2);
                iterate_alnum_front(s, &i1);
                i2--;
        }

        i1 = 1;
        i2 = 1;
        while ( i2 < s.length()){
                if (isalnum(s[i2]))
                        s[i1++] = s[i2];
                else {
                        if (s[i2] != s[i2-1])
                                s[i1++] = s[i2];
                                
                }
                i2++;
        }
        s.erase(i1, s.length() - (i1));

       // get to word pointers on ar start word and one at end
       // traverse till both the words are same, or the start index of both words is different
       // swap these two strings 
}
int main(){
        string str = "   thi, is  one thre,   four.  twoo m   name.  ";
        string str1 = " ";

        string s1 = "this";
        string s2 = "ame";
        int i1 = 0;
        int i2 = 11;
        //swap (str, &i1, s1, &i2, s2);
        //cout<<"#"<<str <<"#"<<endl;
        reversewords (str1);
        cout <<"FINAL : #"<<str1<<"#"<<endl;
        
        return 0;

}

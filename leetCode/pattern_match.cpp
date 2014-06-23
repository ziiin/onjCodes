#include<iostream>
#include<string>
#include<vector>
using namespace std;

int match (string s, int si , string p, int pi) {
        if (pi == p.length())
                return si == s.length();
        if (p[pi + 1] != '*') { // possible segmentation
                return (s[si] == p[pi] || (p[pi] =='.' && si != s.length()) && match(s, si+1, p, pi+1) ); // pi not End
                        //return match(s, si+1, p, pi+1);
        }
         while (s[si] == p[pi] || (p[pi] =='.' && si != s.length()) ) {
         // while both character equal and same as if
                if (match (s, si, p, pi+2) )
                                        return 1;
                si +=1;
               }
        return match (s, si, p, pi+2);

}

bool match1 (const char* s, const char *p) {
        if (*p == '\0')
                return *s == '\0';
        if ( *(p+1) != '*'){
                return ( ( (*s == *p) || (*p =='.' && *s != '\0') ) && match1(s+1,p+1));
        } 
        
        while( (*s == *p) || (*p =='.' && *s != '\0') ){
                if (match1(s,p+2))
                        return true;
                s++;
        }
        return match1(s,p+2);
}


int main() {

        string s;
        string p;
        cin>>s>>p;
        cout<<"matching " <<s<< " and "<<p<<endl; 
        
        
        cout<<(match1(s.c_str(),p.c_str())? "matched" : "NOT matched")<<endl;

        return 0;
}

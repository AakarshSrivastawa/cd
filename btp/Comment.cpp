#include <bits/stdc++.h>
using namespace std;


int main(){
    
    string s, t;
    
    cin>>s;
    int n=s.length();
    if(s.size()>=4)
    {
        if(s[0]=='/' and s[1]=='/') cout<<"It is a single line comment\n";
        else if(s[0]=='/' and s[1]=='*' and s[s.size()-2]=='/' and s[s.size()-3]=='*')
             cout<<"It is a multi line comment"<<endl;
        else  cout<<"It is not a comment"<<endl;
    }
    else
    {
        if(s.size()>=2)
        {
          if(s[0]=='/' and s[1]=='/') cout<<"It is a single line comment"<<endl;
        }
        else cout<<"It is not a comment"<<endl;
    }
    return 0;
}
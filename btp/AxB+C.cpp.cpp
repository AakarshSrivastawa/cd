#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    bool check = 1;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'a');
        else if(s[i] == 'b'){
            for(int j = i; j < s.length(); j++){
                if(s[j] == 'b');
                else{
                    check = 0;
                    break;
                }
            }
            if(check==0) break;
        }
        else{
            check = 0;
            break;
        }
    }
    if(s[s.length()-1] != 'b') check = 0;
    check? cout<<"it is in the form of a*b+"<<endl : cout<<"it is Not in the form of a*b+"<<endl;
    return 0;
}
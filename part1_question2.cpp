#include<bits/stdc++.h>
using namespace std;
int solve(string s){
    if(s.find('m')!=-1||s.find('w')!=-1) return 0;
    int c=0;
    for (int i = 0; i < s.size()-1; ++i) {
        if(s[i]=='u'&&s[i+1]=='u'||s[i]=='n'&&s[i+1]=='n') c++;
    }
    return c+1;
}
int main(){
    string s; cin>>s;
    cout<<solve(s);
}
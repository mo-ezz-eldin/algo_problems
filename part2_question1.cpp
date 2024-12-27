#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>g,vector<int>s){
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    for (int i = 0, j = 0; i < g.size(); ++i) {
        while(j<s.size()&&s[j]<g[i]) j++;
        if(j++==s.size()) return i;
    }
    return g.size();
}
int main(){
    vector<int>g={1,2,3};
    vector<int>s={1,1};
    cout<<solve(g,s);
}
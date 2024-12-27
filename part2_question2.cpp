#include<bits/stdc++.h>
using namespace std;
size_t solve(const vector<char>&tasks, int n){
    int freq[26]={0};
    for(char task : tasks){
        freq[task-'A']++;
    }
    sort(begin(freq),end(freq));
    int gap=freq[25]-1;
    int idle=gap*n;
    for(int i = 24;i>=0;i--)
        idle-=min(gap,freq[i]);
    return idle<=0 ? tasks.size() : tasks.size()+idle;
}
int main(){
    vector<char> v= {'A','A','A', 'B','B','B'};
    int n= 2;
    cout<<solve(v,n);
}
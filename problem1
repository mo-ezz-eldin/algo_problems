#include<bits/stdc++.h>
#define ll long long
#define ll long long
#define nl '\n'
const ll inf=LLONG_MAX;
using namespace std;
ll ans = LLONG_MAX;
class DSU {
public:
    vector<ll> parent, sz;

    DSU(int n) {
        parent.resize(n + 1), sz.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i, sz[i] = 1;
        }

    }

    ll findroot(ll x) {
        if (parent[x] == x)
            return x;
        return parent[x] = findroot(parent[x]);


    }

    bool conn(int u, int v) {
        ll rt_u = findroot(u);
        ll rt_v = findroot(v);
        if (rt_u == rt_v)return true;
        if (sz[rt_v] > sz[rt_u]) swap(rt_u, rt_v);

        sz[rt_u] += sz[rt_v];
        parent[rt_v] = rt_u;

        return false;
    }
};

    struct edge {
        ll c1, c2, w1, w2;

        bool operator<(const edge &other) const {
            return w1 < other.w1;
        }
    };
ll dp[105][50005];
    ll calc(ll ind,ll cur_sum,ll n,ll sum,vector<ll>&v){
        if(ind==n) return(abs(cur_sum-(sum-cur_sum)));
        ll &ret=dp[ind][cur_sum];
        if(ret!=-1) return ret;
        ret=min(calc(ind+1,cur_sum,n,sum,v),calc(ind+1,cur_sum+v[ind],n,sum,v));
        return ret;
    }
    void sol() {
ll n;
cin>>n;
vector<ll>v(n);
ll sum=0;
for(int i=0;i<n;i++){
    cin>>v[i];
    sum+=v[i];

}
        memset(dp,-1,sizeof dp);
cout<<calc(0,0,n,sum,v)<<nl;

    }

    int main() {
        ios_base::sync_with_stdio(false), cin.tie();
        int tc = 1;
cin>>tc;
        while (tc--)
            sol();
    }


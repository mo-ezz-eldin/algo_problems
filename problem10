#include<bits/stdc++.h>
#define ll long long
#define ll long long
#define nl '\n'
const ll N=2e5+5;
using namespace std;
const ll maxN = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 7;
vector<vector<pair<ll, ll>>> g;
vector<ll> p;
vector<ll> s;
vector<ll> chld;
vector<ll> mo(maxN, 0);
ll find_root(ll a) {
    if (p[a] == a) return a;
    return p[a] = find_root(p[a]);
}
void unio(ll a, ll b) {
    a = find_root(a);
    b = find_root(b);
    if (a == b) return;
    if (s[a] < s[b]) swap(a, b);
    s[a] += s[b];
    p[b] = a;
}
ll n, m;
void dfs(ll x, ll p = -1, ll w = -1) {
    for (pair<ll, ll> sz : g[x]) {
        if (sz.first == p) continue;
        dfs(sz.first, x, sz.second);
        chld[x] += chld[sz.first];
    }
    if (p == -1) return;
    mo[w] += chld[x] * (n - chld[x]);
}



void sol() {
    cin >> n >> m;
    vector<pair<ll, pair<ll, ll>>> el;
    g.resize(n + 1);
    p.resize(n + 1);
    s.resize(n + 1, 1);
    chld.resize(n + 1, 1);
    el.resize(m);
    for (ll i = 1; i <= n; i++) p[i] = i;
    for (ll i = 0; i < m; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        el[i] = {z, {x, y}};
    }
    sort(el.begin(), el.end());
    for (ll i = 0; i < m; i++) {
        ll x = el[i].second.first, y = el[i].second.second, z = el[i].first;
        if (find_root(x) != find_root(y)) {
            unio(x, y);
            g[x].push_back({y, z});
            g[y].push_back({x, z});
        }
    }
    dfs(1);
    ll last = 0;
    for (ll i = 0; i < mo.size(); i++) {
        if (mo[i] != 0) last = i;
        if (i == mo.size() - 1) {
            if (mo[i] <= 1) break;
            mo.push_back(mo.back() / 2);
            mo[i] %= 2;
        } else {
            mo[i + 1] += mo[i] / 2;
            mo[i] %= 2;
        }
    }
    for (ll i = last; i >= 0; i--) {
        cout << mo[i];
    }
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie();
    int tc = 1;
   // seive();
//cin>>tc;
    while (tc--)
        sol();
}

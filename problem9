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

    void sol() {
        ll n, m, g, s;
        cin >> n >> m >> g >> s;
        vector<edge> edges(m);
        for (auto &edge: edges)
            cin >> edge.c1 >> edge.c2 >> edge.w1 >> edge.w2;
        sort(edges.begin(), edges.end());

        vector<edge> used;
        for (auto &e: edges) {
            used.push_back(e);
            sort(used.begin(), used.end(), [&](edge &a, edge &b) {
                return a.w2 < b.w2;
            });

            vector<edge> ansi;
            DSU dsu(n);
            ll mx = 0;

            for (auto &es: used)
                if (!dsu.conn(es.c1, es.c2))
                    ansi.push_back(es), mx = max(mx, es.w2);

            used = ansi;

            if (dsu.sz[dsu.findroot(1)] == n)
                ans = min(ans, g * e.w1 + s * mx);//
        }

        cout << (ans == inf ? -1 : ans) << nl;

    }

    int main() {
        ios_base::sync_with_stdio(false), cin.tie();
        int tc = 1;
//cin>>tc;
        while (tc--)
            sol();
    }

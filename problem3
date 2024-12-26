#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100][100];
vector<ll> weight, value;

ll knapSack(int i, ll mx) {
    if (i == weight.size()) return 0;
    ll &ret = dp[i][mx];
    if (ret != -1) return ret;

    ll pick = -1e9;
    if (mx - weight[i] >= 0) {
        pick = value[i] + knapSack(i + 1, mx - weight[i]);
    }
    ll leave = knapSack(i + 1, mx);
    return ret = max(pick, leave);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        ll k, m;
        cin >> k >> m;
        memset(dp, -1, sizeof(dp));
        weight.clear();
        value.clear();

        weight.resize(m);
        value.resize(m);

        for (int i = 0; i < m; ++i) {
            cin >> weight[i] >> value[i];
        }
        ll mx = knapSack(0, k);
        cout << "Hey stupid robber, you can get " << mx << "." << '\n';
    }

    return 0;
}

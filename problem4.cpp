#include <bits/stdc++.h>
#define ll long long
#define el << "\n"
const int N = 100;
using namespace std;
int w, n;
vector<pair<int, int>> v;
int dp[N][N];
vector<pair<int, int>> selected;

int f(int i, int t, vector<pair<int, int>>& taken) {
    if (i == n)
        return 0;
    int& ret = dp[i][t];
    if (~ret)
        return ret;
    int pick = -1;
    vector<pair<int, int>> pick_taken = taken;
    if ((3 * w * v[i].first) <= t) {
        pick_taken.push_back(v[i]);
        pick = f(i + 1, t - (3 * w * v[i].first), pick_taken) + v[i].second;
    }

    int leave = f(i + 1, t, taken);

    if (pick > leave) {
        taken = pick_taken;
        return ret = pick;
    } else {
        return ret = leave;
    }
}

int main() {
    int t;
    while (cin >> t >> w) {
        cin >> n;
        memset(dp, -1, sizeof dp);
        v.resize(n);

        for (int i = 0; i < n; ++i) {
            cin >> v[i].first >> v[i].second;
        }
        vector<pair<int, int>> taken;
        cout << f(0, t, taken) el;
        cout << taken.size() el;
        for (const auto& p : taken) {
            cout << p.first << " " << p.second el;
        }
         cout << "\n";
    }
    return 0;
}

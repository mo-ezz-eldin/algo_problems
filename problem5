#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>lis(20,0);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin >> n;
    vector<ll>a(n);
    for (auto &x : a) cin >> x;
    lis[0] = 1;
    for (int i = 1; i < n; ++i) {
        ll mx = 0;
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i]) mx = max(mx,lis[j]);
        }
        lis[i] = mx + 1;
    }
    int mx = *max_element(lis.begin(), lis.end());
    cout << mx << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int solve(string s) {
     if (s.find('m') != string::npos || s.find('w') != string::npos) 
        return 0;
    int n = s.size();
    vector<long long> ways(n + 1, 0); // ways[i]: number of ways to interpret s[0:i-1]
    ways[0] = 1; 
    for (int i = 1; i <= n; ++i) {
        ways[i] = ways[i - 1]; 
        if (i > 1 && (s[i - 1] == 'u' && s[i - 2] == 'u' || s[i - 1] == 'n' && s[i - 2] == 'n')) {
            ways[i] = (ways[i] + ways[i - 2]) % MOD; 
        }
    }

    return ways[n];
}

int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}

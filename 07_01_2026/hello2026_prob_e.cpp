#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;
const int MAXM = 3005;
vector<int> divisors[MAXM];

void precompute() {
    for (int i = 1; i < MAXM; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            if (i % j == 0) {
                divisors[i].push_back(j);
                if (j * j != i) divisors[i].push_back(i / j);
            }
        }
    }
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    if ((a[1] != 0 && a[1] != 1) || (n >= 2 && a[2] != 0 && a[2] != 2)) {
        cout << 0 << "\n";
        return;
    }

    vector<int> dp(m + 1, 0);
    dp[2] = 1;

    for (int i = 3; i <= n; ++i) {
        vector<int> next_dp(m + 1, 0);
        for (int v = 2; v <= m; ++v) {
            if (dp[v] == 0) continue;
            for (int d : divisors[v]) {
                int nv = v + d;
                if (nv <= m && (a[i] == 0 || a[i] == nv)) {
                    next_dp[nv] = (next_dp[nv] + dp[v]) % MOD;
                }
            }
        }
        dp = next_dp;
    }

    long long total = 0;
    for (int v = 2; v <= m; ++v) {
        if (a[n] == 0 || a[n] == v) total = (total + dp[v]) % MOD;
    }
    cout << total << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
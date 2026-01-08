#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    ll n, m, k;
    if (!(cin >> n >> m >> k)) return;

    ll L_max = k - 1;
    ll R_max = n - k;

    auto check = [&](ll X) {
        if (X <= 1) return true;
        ll needed = X - 1;
        ll min_days = 4e18; // Large value

        for (ll l = 0; l <= needed; ++l) {
            ll r = needed - l;
            if (l <= L_max && r <= R_max) {
                ll cost;
                if (l == 0) {
                    cost = 2 * r - 1;
                } else if (r == 0) {
                    cost = 2 * l - 1;
                } else {
                    // Cost formula for expanding in two directions
                    cost = 2 * max(l, r) + min(l, r) - 1;
                }
                min_days = min(min_days, cost);
            }
        }
        return min_days <= m;
    };

    ll low = 1, high = n, ans = 1;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
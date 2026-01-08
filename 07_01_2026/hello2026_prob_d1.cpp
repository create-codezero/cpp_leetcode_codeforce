#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n + 1, -1);
    vector<int> children_cnt(n + 1, 0);
    vector<int> layer_cnt;
    queue<int> q;

    depth[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (depth[u] >= (int)layer_cnt.size()) {
            layer_cnt.push_back(0);
        }
        layer_cnt[depth[u]]++;

        for (int v : adj[u]) {
            if (depth[v] == -1) {
                depth[v] = depth[u] + 1;
                children_cnt[u]++;
                q.push(v);
            }
        }
    }

    int ans = 0;
    for (int c : layer_cnt) {
        ans = max(ans, c);
    }
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, children_cnt[i] + 1);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
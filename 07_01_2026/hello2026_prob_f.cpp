#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MOD = 998244353;
const int MAXN = 5005;

int G[MAXN][MAXN];
int R[MAXN][MAXN];
vector<int> adj[MAXN];
vector<int> children[MAXN];
int post_order[MAXN];
int po_ptr;
string S;

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v != p) {
            children[u].push_back(v);
            dfs(v, u);
        }
    }
    post_order[po_ptr++] = u;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    cin >> S;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        children[i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    po_ptr = 0;
    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            G[i][j] = 0;
            R[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        int u = post_order[i];
        for (int j = 0; j < n; j++) {
            int v = post_order[j];

            long long H = 0;
            for (int vc : children[v]) {
                H += (G[u][vc] - R[u][vc] + MOD);
            }
            H %= MOD;

            int f = (S[u - 1] == S[v - 1]) ? (1 + (int)H) % MOD : 0;

            long long sumR = 0;
            for (int vc : children[v]) {
                sumR += R[u][vc];
            }
            R[u][v] = (f + (int)(sumR % MOD)) % MOD;

            long long sumG = 0;
            for (int uc : children[u]) {
                sumG += G[uc][v];
            }
            G[u][v] = (R[u][v] + (int)(sumG % MOD)) % MOD;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << G[i][i] << (i == n ? "" : " ");
    }
    cout << "\n";
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
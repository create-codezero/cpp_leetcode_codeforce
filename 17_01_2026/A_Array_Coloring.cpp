#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> r;
        vector<vector<int>> b;
        r.reserve(n);
        b.reserve(n);

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;

            vector<int> curr(2);
            curr[0] = val;

            if ((i + 1) % 2 == 0) {
                // even position
                curr[1] = 1;
                r.push_back(curr);

                curr[1] = 0;
                b.push_back(curr);
            } else {
                // odd position
                curr[1] = 0;
                r.push_back(curr);

                curr[1] = 1;
                b.push_back(curr);
            }
        }

        sort(r.begin(), r.end());
        sort(b.begin(), b.end());

        int rprev = -1, bprev = -1;
        int rOut = 0, bOut = 0;

        for (int j = 0; j < n; j++) {
            if (rprev == r[j][1]) rOut++;
            if (bprev == b[j][1]) bOut++;

            rprev = r[j][1];
            bprev = b[j][1];
        }

        if (rOut && bOut) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}

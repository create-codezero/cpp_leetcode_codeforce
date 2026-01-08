#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXN 200005
bool seen[MAXN];

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    int *results = (int *)malloc(t * sizeof(int));
    if (results == NULL) return 1;

    for (int tc = 0; tc < t; tc++) {
        int n, k;
        scanf("%d %d", &n, &k);

        for (int i = 0; i <= n + 1; i++) {
            seen[i] = false;
        }

        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            if (val <= n) {
                seen[val] = true;
            }
        }

        int original_mex = 0;
        while (seen[original_mex]) {
            original_mex++;
        }

        int limit = k - 1;
        results[tc] = (limit < original_mex) ? limit : original_mex;
    }

    for (int tc = 0; tc < t; tc++) {
        printf("%d\n", results[tc]);
    }

    free(results);
    return 0;
}
#include <cstdio>
#include <algorithm>

typedef unsigned long long ull;

const int N = 1000010;
const ull P = 1000000007;

int n, v[N], l[N], r[N], best = 1;
ull H[N << 1];

int dfs(int u, ull& pre, ull& suf, int& Virtual) {
    if (u == -1) {
        pre = suf = 1001;
        Virtual = 1;
        return 1;
    }

    ull lpre, lsuf; int lv;
    int ln = dfs(l[u], lpre, lsuf, lv);
    ull rpre, rsuf; int rv;
    int rn = dfs(r[u], rpre, rsuf, rv);

    Virtual = lv + rv;
    pre = v[u] * H[ln + rn] + lpre * H[rn] + rpre;
    suf = v[u] * H[ln + rn] + rsuf * H[ln] + lsuf;

    if (lpre == rsuf) {
        int tmp = ln + rn + 1 - Virtual;
        // if (tmp > 1) {
        //     printf("%d\n", tmp);
        // }
        best = std::max(best, tmp);
    }
    return ln + rn + 1;
}   // return num of node

void init() {
    H[0] = 1;
    for (int i = 1; i < (N << 1); ++i) {
        H[i] = H[i - 1] * P;
    }
}

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w" ,stdout);

    init();

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &v[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
    }
    ull pre, suf; int Virtual;
    dfs(1, pre, suf, Virtual);

    printf("%d\n", best);

    return 0;
}

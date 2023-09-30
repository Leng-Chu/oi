#include <cstdio>
#include <climits>

typedef long long LL;

const int N = 100010;

int n, m, p1;
LL c[N], s1, s2;

LL ABS(LL x) { return x < 0 ? -x : x; }

int main() {
    freopen("fight.in", "r", stdin);
    freopen("fight.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &c[i]);
    }
    scanf("%d%d%lld%lld", &m, &p1, &s1, &s2);
    LL sum = (m - p1) * s1, best = LLONG_MAX; int k = -1;
    for (int i = 1; i <= n; ++i) {
        sum += (m - i) * c[i];
    }
    for (int i = 1; i <= n; ++i) {
        LL tmp = ABS(sum + (m - i) * s2);
        if (tmp < best) {
            best = tmp;
            k = i;
        }
    }
    printf("%d\n", k);

    return 0;
}

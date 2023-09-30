#include <stdio.h>
typedef long long LL;
const LL min_ll = -1e18;
int n, m; LL w[1005][1005], f[1005][1005][2];
inline LL mx(LL p, LL q, LL r) {return p > q ? (p > r ? p : r) : (q > r ? q : r);}
inline LL dfs(int x, int y, int from) {
    if (x < 1 || x > n || y < 1 || y > m) return min_ll;
    if (f[x][y][from] != min_ll) return f[x][y][from];
    if (from == 0) f[x][y][from] = mx(dfs(x + 1, y, 0), dfs(x, y - 1, 0), dfs(x, y - 1, 1)) + w[x][y];
    else f[x][y][from] = mx(dfs(x - 1, y, 1), dfs(x, y - 1, 0), dfs(x, y - 1, 1)) + w[x][y];
    return f[x][y][from];
}
int main(void) {
	freopen("number.in", "r", stdin); 
    freopen("number.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			scanf("%lld", &w[i][j]);
			f[i][j][0] = f[i][j][1] = min_ll;
		}
    f[1][1][0] = f[1][1][1] = w[1][1];
	printf("%lld\n", dfs(n, m, 1));
	return 0;
}
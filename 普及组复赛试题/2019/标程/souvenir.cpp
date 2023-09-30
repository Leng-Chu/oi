#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int MAXN = 105;

//dp[k]表示手里剩k元现金的时候，明天早上都卖了以后的钱数
//price[i][j]表示第i天第j件物品的价格
int dp[10005], price[MAXN][MAXN];

int main()
{
	freopen("souvenir.in","r",stdin);
	freopen("souvenir.out","w",stdout);
	int t, n, m, ans;
	scanf("%d%d%d", &t, &n, &m);
	//先输入
	for (int i = 1; i <= t; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			scanf("%d", &price[i][j]);
		}
	}
	//第一天早上手里有m元
	ans = m;
	for (int i = 1; i < t; ++i)
	{
		//先把数组赋值为负无穷
		memset(dp, ~0x3f, sizeof(dp));
		//什么都不买，今天早上有ans元，明天早上也是ans元
		dp[ans] = ans;
		//枚举第j个物品
		for (int j = 1; j <= n; ++j)
		{
			//手里有k元的时候，去推明天早上的钱
			for (int k = ans; k >= price[i][j]; --k)
			{
				//买一件物品，现金减少，赚一份差价，完全背包倒着循环
				dp[k - price[i][j]] = max(dp[k - price[i][j]], dp[k] + price[i + 1][j] - price[i][j]);
			}
		}
		//找一下明天早上收益最大
		int ma = 0;
		for (int j = 0; j <= ans; ++j)
		{
			ma = max(ma, dp[j]);
		}
		//明天早上就有这么多钱了，继续赚钱
		ans = ma;
	}
	cout << ans << endl;
	return 0;
}

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int MAXN = 105;

//dp[k]��ʾ����ʣkԪ�ֽ��ʱ���������϶������Ժ��Ǯ��
//price[i][j]��ʾ��i���j����Ʒ�ļ۸�
int dp[10005], price[MAXN][MAXN];

int main()
{
	freopen("souvenir.in","r",stdin);
	freopen("souvenir.out","w",stdout);
	int t, n, m, ans;
	scanf("%d%d%d", &t, &n, &m);
	//������
	for (int i = 1; i <= t; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			scanf("%d", &price[i][j]);
		}
	}
	//��һ������������mԪ
	ans = m;
	for (int i = 1; i < t; ++i)
	{
		//�Ȱ����鸳ֵΪ������
		memset(dp, ~0x3f, sizeof(dp));
		//ʲô�����򣬽���������ansԪ����������Ҳ��ansԪ
		dp[ans] = ans;
		//ö�ٵ�j����Ʒ
		for (int j = 1; j <= n; ++j)
		{
			//������kԪ��ʱ��ȥ���������ϵ�Ǯ
			for (int k = ans; k >= price[i][j]; --k)
			{
				//��һ����Ʒ���ֽ���٣�׬һ�ݲ�ۣ���ȫ��������ѭ��
				dp[k - price[i][j]] = max(dp[k - price[i][j]], dp[k] + price[i + 1][j] - price[i][j]);
			}
		}
		//��һ�����������������
		int ma = 0;
		for (int j = 0; j <= ans; ++j)
		{
			ma = max(ma, dp[j]);
		}
		//�������Ͼ�����ô��Ǯ�ˣ�����׬Ǯ
		ans = ma;
	}
	cout << ans << endl;
	return 0;
}

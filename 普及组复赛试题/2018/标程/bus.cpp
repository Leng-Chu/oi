//100pts 500 100 4e6
#include<cstdio>
#include<algorithm>

#define INF 2147483647

int n,m;
int data[1024];
int sum[1024];
int dp[1024][128];

int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",data+i);
	std::sort(data+1,data+n+1);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+data[i];
	for(int i=1;i<=n;++i)
		for(int j=0;j<m;++j)
			{
			int now=data[i]+j;
			if(j)dp[i][j]=dp[i][j-1];
			else dp[i][j]=now*i-sum[i];
			for(int last=std::max(now-2*m+1,0);last<=now-m;++last)
				{
				int x=std::lower_bound(data+1,data+n+1,last+1)-data-1;
				int y=std::min(last-data[x],m-1);
				int tmp=dp[x][y]+(i-x)*now-(sum[i]-sum[x]);
				if(tmp<dp[i][j])dp[i][j]=tmp;
				}
			}
	printf("%d\n",dp[n][m-1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
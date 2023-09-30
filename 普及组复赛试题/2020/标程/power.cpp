#include<bits/stdc++.h>
using namespace std;

const int maxn=100005;

int n;

long long now=1; //now代表二的次数幂。 

bool a[105];

int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	
	scanf("%d",&n);
	
	if (n%2!=0)
	{
		printf("-1");
		return 0;
	} //如果n为奇数，直接输出-1。 
	
	int i=0; //i用来存最高次数。 
	
	while(now*2<=n)
	{
		now*=2;
		i++;
	} //先将最大的幂求出来。 
	
	int i1=i; //这里不能直接用i，后面还要用到。 
	
	while(now>1)
	{
		if (n-now>=0)
		{
			a[i1]=1;
			n-=now;
		}
		i1--;
		now/=2;
	} //看每一次数有没有。 
	
	for (register int j=i;j>=1;--j)
	{
		if (a[j]==0) continue;
		long long ans=pow(2,j);
		printf("%lld ",ans);
	} //最后在输出拆分出来的，记住从大到小。 
	
	return 0; //一定要返回值0。 
}
#include<bits/stdc++.h>
using namespace std;
int n;
int q[3000010],tim[3000010],h=1,t=1;
int book[300010],cnt;
int main()
{
    freopen("port.in","r",stdin);
    freopen("port.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int ti,k;
		scanf("%d%d",&ti,&k);
		for(int j=1;j<=k;j++)
		{
			int x;
			scanf("%d",&x);
			q[t]=x; tim[t++]=ti;
			book[x]++; if(book[x]==1) cnt++;
		}
		while(ti-tim[h]>=86400)
		{
			book[q[h]]--;
			if(!book[q[h]]) cnt--;
			h++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
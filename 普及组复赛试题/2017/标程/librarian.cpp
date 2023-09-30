#include<bits/stdc++.h>
using namespace std;
long long b[1010],qaq[1010],tmp[1010],qwq[1010];
int n,q;
int main()
{
    freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=1; i<=1001; i++) tmp[i]=1;
	for (int i=1; i<=n; i++) scanf("%lld",&b[i]);
	sort(b,b+n+1);
	for (int i=1; i<=q; i++)
	{
		scanf("%lld%lld",&qwq[i],&qaq[i]);
		for (int j=1; j<=qwq[i]; j++) tmp[i]*=10;
	}
	for (int i=1; i<=q; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (b[j]%tmp[i]==qaq[i])
			{
				printf("%lld\n",b[j]);
				break;
			}
			else if (j==n)
			{
				printf("-1\n");
				break;
			}
		}
	}
	return 0;
}
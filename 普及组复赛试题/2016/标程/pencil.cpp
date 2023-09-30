#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int sum=99999999;
int main()
{
    freopen("pencil.in","r",stdin);
    freopen("pencil.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=3;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(n%a==0) sum=min(sum,n/a*b);
		else sum=min(sum,(n/a+1)*b);
	}
	printf("%d",sum);
	return 0;
}
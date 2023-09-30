#include<bits/stdc++.h>
using namespace std;
int opt,n,t[100001],p[100001],ans,top,m=1,yh[100001],sj[100001],k;//m即为可以使用的优惠券的左端点值，top为右端点值
bool r[100001];//记录当前票是否用过
int main()
{
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d%d%d",&opt,&p[i],&t[i]);
		if(opt==0) yh[++top]=p[i],sj[top]=t[i],ans+=p[i];//如果做的是地铁，直接将票价和时间加入
		else
		{
			k=0;//k用来判断是否有票符合条件
			for(int j=m; j<=top; j++) //从1开始必然TLE 实测大概大样例要跑2s
			{
				if(r[j]) continue;//如果用过直接跳过
				if(t[i]-sj[j]>45) m=j;//如果当前差已经大于45（注意等于是可以的），直接更改左端点值
				else if(yh[j]>=p[i])
				{
					k=j;//只要有能用的直接用
					r[k]=true;//记录已经使用
					break;//退出循环
				}
			}
			if(!k) ans+=p[i];//如果用了即k被赋值，则不用出钱，否则还是要付钱的
		}
	}
	printf("%d",ans);
}

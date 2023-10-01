#include<bits/stdc++.h>
using namespace std;
int tim[100010],pri[100010],head=1,tail=0;
//用队列存储当前有用的优惠票 需要建两个队列 一个存储时间 一个存储价格
int main()
{
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    int n,ans=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        int opt,p,t;
        scanf("%d%d%d",&opt,&p,&t);
        if(opt==0)
        {
            tail++;
            tim[tail]=t;
            pri[tail]=p;
            //如果坐的是地铁，直接将票价和时间加入队列
            ans+=p;//坐地铁一定会花钱
        }
        else
        {
            int flag=0;
            //0表示还没有找到符合条件的优惠票
            //非0表示最早的符合条件的优惠票编号为flag
            while(t-tim[head]>45&&head<=tail) head++;
            //需要保证队列中有元素 即head<=tail
            //队头是最早入队的优惠票 如果超时了 出队
            for(int j=head; j<=tail; j++)
            {
                if(pri[j]>=p)//如果这个优惠票价格大于p 可以用
                {
                    flag=j;//最早的符合条件的优惠票编号为flag
                    pri[j]=0;//把价格置零表示这张优惠票已经用过了
                    break;//退出循环
                }
            }
            if(flag==0) ans+=p;//如果用了优惠票则不用出钱，否则还是要付钱的
        }
    }
    printf("%d",ans);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int tim[100010],pri[100010],head=1,tail=0;
//�ö��д洢��ǰ���õ��Ż�Ʊ ��Ҫ���������� һ���洢ʱ�� һ���洢�۸�
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
            //��������ǵ�����ֱ�ӽ�Ʊ�ۺ�ʱ��������
            ans+=p;//������һ���ỨǮ
        }
        else
        {
            int flag=0;
            //0��ʾ��û���ҵ������������Ż�Ʊ
            //��0��ʾ����ķ����������Ż�Ʊ���Ϊflag
            while(t-tim[head]>45&&head<=tail) head++;
            //��Ҫ��֤��������Ԫ�� ��head<=tail
            //��ͷ��������ӵ��Ż�Ʊ �����ʱ�� ����
            for(int j=head; j<=tail; j++)
            {
                if(pri[j]>=p)//�������Ż�Ʊ�۸����p ������
                {
                    flag=j;//����ķ����������Ż�Ʊ���Ϊflag
                    pri[j]=0;//�Ѽ۸������ʾ�����Ż�Ʊ�Ѿ��ù���
                    break;//�˳�ѭ��
                }
            }
            if(flag==0) ans+=p;//��������Ż�Ʊ���ó�Ǯ��������Ҫ��Ǯ��
        }
    }
    printf("%d",ans);
    return 0;
}
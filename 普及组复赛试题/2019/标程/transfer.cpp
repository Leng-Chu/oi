#include<bits/stdc++.h>
using namespace std;
int opt,n,t[100001],p[100001],ans,top,m=1,yh[100001],sj[100001],k;//m��Ϊ����ʹ�õ��Ż�ȯ����˵�ֵ��topΪ�Ҷ˵�ֵ
bool r[100001];//��¼��ǰƱ�Ƿ��ù�
int main()
{
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d%d%d",&opt,&p[i],&t[i]);
		if(opt==0) yh[++top]=p[i],sj[top]=t[i],ans+=p[i];//��������ǵ�����ֱ�ӽ�Ʊ�ۺ�ʱ�����
		else
		{
			k=0;//k�����ж��Ƿ���Ʊ��������
			for(int j=m; j<=top; j++) //��1��ʼ��ȻTLE ʵ���Ŵ�����Ҫ��2s
			{
				if(r[j]) continue;//����ù�ֱ������
				if(t[i]-sj[j]>45) m=j;//�����ǰ���Ѿ�����45��ע������ǿ��Եģ���ֱ�Ӹ�����˵�ֵ
				else if(yh[j]>=p[i])
				{
					k=j;//ֻҪ�����õ�ֱ����
					r[k]=true;//��¼�Ѿ�ʹ��
					break;//�˳�ѭ��
				}
			}
			if(!k) ans+=p[i];//������˼�k����ֵ�����ó�Ǯ��������Ҫ��Ǯ��
		}
	}
	printf("%d",ans);
}

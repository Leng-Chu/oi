#include<iostream>
using namespace std;
int ans=0;//ans������
char s[21];//�ַ�������һ��
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<8; i++) //ģ��
	{
		if(s[i]=='1') //�ж��Ƿ�Ϊ1
		{
			ans++;//������++
		}
	}
	cout<<ans<<endl;
	return 0;//��������
}

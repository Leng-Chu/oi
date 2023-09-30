#include<iostream>
using namespace std;
int ans=0;//ans计数器
char s[21];//字符串开大一点
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<8; i++) //模拟
	{
		if(s[i]=='1') //判断是否为1
		{
			ans++;//计数器++
		}
	}
	cout<<ans<<endl;
	return 0;//完美结束
}

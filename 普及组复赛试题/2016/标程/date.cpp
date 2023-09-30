#include<bits/stdc++.h>
using namespace std;
int ys,ms,ds,yt,mt,dt,ans;
void read()
{
	char s[10];
	scanf("%s",s);
	for(int i=0;i<4;i++) ys=ys*10+s[i]-'0';
	for(int i=4;i<6;i++) ms=ms*10+s[i]-'0';
	for(int i=6;i<8;i++) ds=ds*10+s[i]-'0';
	scanf("%s",s);
	for(int i=0;i<4;i++) yt=yt*10+s[i]-'0';
	for(int i=4;i<6;i++) mt=mt*10+s[i]-'0';
	for(int i=6;i<8;i++) dt=dt*10+s[i]-'0';
}
int getday(int x)
{
	if(x==1||x==3||x==5||x==7||x==8||x==10||x==12) return 31;
	else if(x==2) return 29;
	else return 30;
}
int getyear(int m,int d)
{
	int y=0;
	y+=d%10*1000+d/10*100;
	y+=m%10*10+m/10;
	return y;
}
bool check(int y,int m,int d)
{
	if(y<ys||y>yt) return 0;
	if(y==ys&&(m<ms||(m==ms&&d<ds))) return 0;
	if(y==yt&&(m>mt||(m==mt&&d>dt))) return 0;
	return 1;
}
int main()
{
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
	read();
	for(int m=1;m<=12;m++)
	{
		int up=getday(m);//判断这个月有多少天 
		for(int d=1;d<=up;d++)
		{
			if(d%10==0) continue;//年份首位不为0 
			int y=getyear(m,d);//通过月和日来判断回文的年份 
			if(check(y,m,d)) ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
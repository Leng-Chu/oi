#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("score.in","r",stdin);
    freopen("score.out","w",stdout);
	double a,b,c;
	cin>>a>>b>>c;
	double ans=a*0.2+b*0.3+c*0.5;
	printf("%d",(int)ans);
	return 0;
}
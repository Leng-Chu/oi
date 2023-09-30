#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[110][110],minn[110][110];
void dfs(int x,int y,int cost,int ma)
{
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int tx,ty;
	if(cost>=minn[x][y]) return;
	if(cost<minn[x][y]) minn[x][y]=cost;
	if(x==n&&y==n) return;
	for(int i=0;i<=3;i++)
	{
		tx=x+next[i][0]; ty=y+next[i][1];
		if(tx<1||ty<1||tx>n||ty>n) continue;
		if(a[tx][ty]==a[x][y]) dfs(tx,ty,cost,1);
		else if(a[tx][ty]==0&&ma)
		{
			a[tx][ty]=a[x][y];
			dfs(tx,ty,cost+2,0);
			a[tx][ty]=0;
		}
		else if(a[tx][ty]!=0) dfs(tx,ty,cost+1,1);
	}
}
int main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) minn[i][j]=99999999;
	for(int i=1;i<=m;i++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		if(c==0) a[x][y]=2;
		else a[x][y]=1;
	}
	dfs(1,1,0,1);
	if(minn[n][n]==99999999) printf("-1");
	else printf("%d",minn[n][n]);
	return 0;
}
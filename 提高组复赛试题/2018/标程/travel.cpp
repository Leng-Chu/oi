#include<bits/stdc++.h>
using namespace std;
int n,m,flag;
int s[5010],top,ans[5010];
bool inc[5010][5010],ban[5010][5010],chg,book[5010];
vector<int> h[5010];

void dfs(int u,int fa)
{
	s[++top]=u;
	if(s[top]<ans[top]) chg=1;
	if(s[top]>ans[top]&&!chg) return;
	int len=h[u].size();
	for(int i=0;i<len;i++)
	{
		int v=h[u][i];
		if(ban[u][v]||v==fa) continue;
		dfs(v,u);
		if(s[top]>ans[top]&&!chg) return;
	}
}
void solve1()
{
	dfs(1,-1);
	for(int i=1;i<=n;i++) printf("%d ",s[i]);
}
void findc(int u,int fa)
{
	book[u]=1; int len=h[u].size();
	for(int i=0;i<len;i++)
	{
		int v=h[u][i];
		if(v==fa) continue;
		if(book[v])
		{
			inc[u][v]=1;
			flag=v;
			return;
		}
		findc(v,u);
		if(flag!=0)
		{
			if(flag==-1) return;
			else
			{
				inc[u][v]=inc[v][u]=1;
				if(u==flag) flag=-1;
				return;
			}
		}
	}
}
void solve2()
{
	findc(1,-1);
	for(int i=1;i<=n;i++)
	{
		int len=h[i].size();
		for(int j=0;j<len;j++)
		{
			int v=h[i][j];
			if(!inc[i][v]||v<i) continue;
			ban[i][v]=ban[v][i]=1;
			chg=0; top=0; dfs(1,-1);
			if(chg) for(int i=1;i<=n;i++) ans[i]=s[i];
			ban[i][v]=ban[v][i]=0;
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		h[u].push_back(v);
		h[v].push_back(u);
	}
	for(int i=1;i<=n;i++) sort(h[i].begin(),h[i].end());
	memset(ans,0x3f,sizeof(ans));
	if(m==n-1) solve1();
	else solve2();
	return 0;
}
#include<bits/stdc++.h>
#define MAXN 500010
#define ll long long
using namespace std;   
int n,m,i,j,k,dis[MAXN],q[MAXN],a[MAXN],d,L,R,xl,xr,dp[MAXN];    
ll S,Ans; 
namespace Fastio{ //快读快写
    int read(){ //快读
        int x=0,f=1;char c=getchar();
        while(!isdigit(c)){if(c=='-')f=-1;c=getchar();} 
        while(isdigit(c)){x=x*10+c-48;c=getchar();}
        return x*f;
    }
    void write(int x){ //快写
        if(x/10>0) write(x/10);
        putchar(x%10+48);
        return;
    }
}   
using namespace Fastio;   
void mem(){ //初始化，这里需要初始化的东西比较少，所以不用也可以
    memset(dp,-1,sizeof(dp));    
    memset(q,0,sizeof(q));
    dp[0]=0;
}    
bool check(int xl,int xr){
    int i,j=0;
    mem();
    int Head=1;int Last=0;
    for(i=1;i<=n;i++){
        while(dis[i]-dis[j]>=xl&&j<i){
            if(dp[j]!=-1){
                while(Head<=Last&&dp[q[Last]]<=dp[j]) --Last;
                q[++Last]=j;
            }
            j++;
        }
        while(Head<=Last&&dis[i]-dis[q[Head]]>xr) ++Head;
        if(Head<=Last) dp[i]=dp[q[Head]]+a[i];
    }
    for(i=1;i<=n;i++){
        if(dp[i]>=k) return 1;
    }
    return 0;
}
int main(){
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    n=read();d=read();k=read();
    for(i=1;i<=n;i++){
        dis[i]=read();a[i]=read();
        if(S!=-8888&&a[i]>0) S+=a[i];
        if(S>=k) S=-8888;	
    }
    if(S!=-8888){
        printf("-1");
        return 0;
    }
    L=0;R=dis[n];   
    while(L<=R){
        int mid=L+R>>1;
        if(mid>=d) xl=1;
        else xl=d-mid;
        xr=d+mid;
        if(check(xl,xr)) {Ans=mid;R=mid-1;}
        else L=mid+1;
    }
    printf("%d",Ans);
    return 0;
}
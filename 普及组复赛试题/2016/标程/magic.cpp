#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,a[40001],w[30001],ans[4][30001];
int main()
{
    freopen("magic.in","r",stdin);
    freopen("magic.out","w",stdout);
    int i,j,k;
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
        w[a[i]]++;
    }
    for (i=1;i<=n/9;i++)
    {
        int x=8*i+1,y=0;
        for (j=n-9*i+1;j>=1;j--)
        {
            y+=w[j+x]*w[j+x+i];
            ans[0][j]+=w[j+2*i]*y;
            ans[1][j+2*i]+=w[j]*y;
        }
        y=0;
        for (j=x+1;j<=n;j++)
        {
            y+=w[j-x]*w[j-x+2*i];
            ans[2][j]+=w[j+i]*y;
            ans[3][j+i]+=w[j]*y;
        }
    }
    for (i=1;i<=m;i++) 
        printf("%d %d %d %d\n",ans[0][a[i]],ans[1][a[i]],ans[2][a[i]],ans[3][a[i]]);
    return 0;
}
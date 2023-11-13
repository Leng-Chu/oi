#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
long long ans=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++) if(a[i]>a[i-1]) ans+=a[i]-a[i-1];
    cout<<ans+a[1];
    return 0;
}
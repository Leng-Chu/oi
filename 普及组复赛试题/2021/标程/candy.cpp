#include<bits/stdc++.h>
using namespace std;
int n,l,r;
int main(){
    freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>l>>r;
	cout<<min(r,l+(n-1-l%n))%n;  //先尝试将余数补到n-1，如果超过r，那么结果就是r mod n，否则就是n-1
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int a[500010];
int sta[100010],p=0;
int zhi[500010],cnt;
int tree[500010][2]; 
int what[500010];
int c[500010];
int main(){
    freopen("expr.in", "r", stdin);
    freopen("expr.out", "w", stdout);
	getline(cin,s);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	cnt=n;
	for(int i=0;i<s.size();i++){
		if(s[i]=='x'){
			i++;
			int f=0;
			while(isdigit(s[i])){
				f=f*10+s[i]-'0';
				i++;
			} 
			sta[++p]=f;
			what[f]=0;
		}else if(s[i]=='&'){
			what[++cnt]=1;
			tree[cnt][1]=sta[p--];
			tree[cnt][0]=sta[p--];
			a[cnt]=a[tree[cnt][0]]&a[tree[cnt][1]];
			sta[++p]=cnt;
		}else if(s[i]=='|'){
			what[++cnt]=2;
			tree[cnt][1]=sta[p--];
			tree[cnt][0]=sta[p--];
			a[cnt]=a[tree[cnt][0]]|a[tree[cnt][1]];
			sta[++p]=cnt;
		}else if(s[i]=='!'){
			what[++cnt]=3;
			tree[cnt][0]=sta[p--];
			a[cnt]=!a[tree[cnt][0]];
			sta[++p]=cnt;
		}
	}
	c[cnt]=1;
	for(int i=cnt;i>n;i--){
		int l=tree[i][0],r=tree[i][1];
		if(what[i]==1){
			if(((!a[l])&a[r])!=a[i])c[l]=c[i];
			if((a[l]&(!a[r]))!=a[i])c[r]=c[i]; 
		}else if(what[i]==2){
			if(((!a[l])|a[r])!=a[i])c[l]=c[i];
			if((a[l]|(!a[r]))!=a[i])c[r]=c[i]; 
		}else if(what[i]==3){
			c[l]=c[i]; 
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int k;
		scanf("%d",&k);
		printf("%d\n",a[cnt]^c[k]);
	} 
	return 0;
}
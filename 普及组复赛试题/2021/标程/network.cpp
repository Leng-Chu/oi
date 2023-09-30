#include<bits/stdc++.h>
using namespace std;
map<string,int> vis;
int n;
bool check(char s[]){
	int a=-1,b=-1,c=-1,d=-1,e=-1;
	int t=sscanf(s,"%d.%d.%d.%d:%d",&a,&b,&c,&d,&e);//尝试读入，保存至s中
	if(t!=5) return 0;//没有5个肯定不行
	if(a<0||a>255) return 0;
	if(b<0||b>255) return 0;
	if(c<0||c>255) return 0;
	if(d<0||d>255) return 0;
	if(e<0||e>65535) return 0;//判断
	char s2[35];
	sprintf(s2,"%d.%d.%d.%d:%d",a,b,c,d,e);//保存至s2中
	int lens=strlen(s);//接下来判断s2和s是否一样
	bool ok=0;
	for(int i=0;i<lens;i++){
		if(s[i]==s2[i]) ok=1;
		else{
			ok=0;
			break;
		}
	}
	return ok;
}
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		char op[1005],ad[1005];
		cin>>op>>ad;
		string t(ad);
		if(op[0]=='S'){//服务机
			if(!check(ad)) cout<<"ERR"<<endl;//判断是否合法
			else if(vis.count(t)!=0){//之前有了，输出FAIL
				cout<<"FAIL"<<endl;
			} 
			else{
				cout<<"OK"<<endl;
				vis[t]=i;//保存编号
			}
		}
		else{//客户机
			if(!check(ad)){//判断是否合法
				cout<<"ERR"<<endl; 
			}
			else if(vis.count(t)==0){//如果之前还没有相同地址串的服务机，输出FAIL
				cout<<"FAIL"<<endl;
			}
			else{
				cout<<vis[ad]<<endl;//否则就是可以连接，输出连接编号
			}
		}
	}
}
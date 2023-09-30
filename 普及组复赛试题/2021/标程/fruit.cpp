#include<bits/stdc++.h>
using namespace std;
struct lian{//数链表，同时维护数值 
	int lst,nxt;
	int num;
}a[200005];
struct kuai{//块链表，同时维护这个块的头和尾 
	int lst,nxt=0;
	int bg,ed;
}blk[200005];
int n;
int sumk,lshead=0;
void delnum(int x){
	printf("%d ",blk[x].bg);
	a[a[blk[x].bg].lst].nxt=a[blk[x].bg].nxt;
	a[a[blk[x].bg].nxt].lst=a[blk[x].bg].lst;
	blk[x].bg=a[blk[x].bg].nxt;
}
void delblock(int i){
	blk[blk[i].nxt].lst=blk[i].lst;
	blk[blk[i].lst].nxt=blk[i].nxt;
	sumk--;
}
int main(){
	freopen("fruit.in","r",stdin);
	freopen("fruit.out","w",stdout);
	scanf("%d",&n);
	a[0].num=1919810;
	for(int i=1;i<=n;i++){//建立链表 
		scanf("%d",&a[i].num);
		a[i].lst=i-1,a[i].nxt=i+1;
		if(a[i].num!=a[i-1].num){
			blk[lshead].nxt=i;
			blk[i].lst=lshead;
			blk[i].bg=i;blk[lshead].ed=i-1;
			lshead=i;
			sumk++;
		}
	}
	blk[lshead].ed=n;
	while(sumk){
		for(int i=blk[0].nxt;i!=0;i=blk[i].nxt){//删除块 
			if(blk[i].bg>blk[i].ed){
				delblock(i);
			}else{//合并块 
				if(a[blk[i].bg].num==a[blk[blk[i].lst].ed].num){
					blk[blk[i].lst].ed=blk[i].ed;
					delblock(i);
				}
			}
		}
		for(int i=blk[0].nxt;i!=0;i=blk[i].nxt){//删数 
			delnum(i);
		}
		if(sumk)putchar('\n');
	}
    return 0;
}
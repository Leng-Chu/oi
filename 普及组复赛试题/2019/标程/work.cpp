#include<bits/stdc++.h>
#define N 100005
using namespace std;

struct Edge{
	int to , next;
}edge[N << 1];
int head[N] , tot = 0 , in[N];

struct node{
	int pos , dis;
};

queue < node > q;

void add(int u , int v){
	edge[++tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot;
}

int n , m , Q;
int dis1[N] , dis2[N];
bool vis1[N] , vis2[N];

void bfs(){
	memset(dis1 , 0x3f , sizeof(dis1));
	memset(dis2 , 0x3f , sizeof(dis2));
	q.push((node){1 , 0});
	dis2[1] = 0;
	while(!q.empty()){
		node tmp = q.front();
		q.pop();
		int x = tmp.pos , d = tmp.dis + 1;
		for(int i = head[x]; i; i = edge[i].next){
			int v = edge[i].to;
			if(d < dis1[v] && d % 2 != 0){
				dis1[v] = d;
				q.push((node){v , d});
			}
			if(d < dis2[v] && d % 2 == 0){
				dis2[v] = d;
				q.push((node){v , d});
			}
		}
	}
}
				

int main(){
	freopen("work.in" , "r" , stdin);
	freopen("work.out" , "w" , stdout);
	cin >> n >> m >> Q;
	for(int i = 1; i <= m; i++){
		int u , v;
		scanf("%d%d" , &u , &v);
		add(u , v); add(v , u);
		in[u] ++;
		in[v] ++;
	}
	
	bfs();
	
	while(Q--){
		int A , L;
		scanf("%d%d" , &A , &L);
		if(in[A] == 0 && L != 0) { printf("No\n"); continue; }
		if(L % 2 == 0){
			if(L - dis2[A] >= 0) printf("Yes\n");
			else printf("No\n");
		}
		else{
			if(L - dis1[A] >= 0)  printf("Yes\n");
			else printf("No\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

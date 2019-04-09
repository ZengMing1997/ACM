#include<bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
vector<int>edge[1000] , ans;
priority_queue<int,vector<int>,greater<int> >q;//从大到小，反向输出 
int in[1000];
int vis[1000][1000]; 
int T , n , m;
void init()
{
	for(int i = 1 ; i<= n ;i++)
	{
		edge[i].clear();
		in[i] = 0;
	}
	while(!q.empty()) q.pop();
	ans.clear();
	memset(vis , 0 , sizeof(vis));
}
void solve()
{
	for(int i = 1 ; i <= n ; i++)
	{
		if(in[i] == 0)q.push(i); //寻找度为0节点放入优先队列 
	}
	while(!q.empty())
	{
		int p = q.top();
		q.pop();
		ans.push_back(p);//排的序列 
		//与度为0相连的边减减 
		for(int i = 0 ; i < edge[p].size() ; i++)
		{
			int v = edge[p][i];
			in[v]--;
			if(in[v] == 0) q.push(v);//入度为0放入队列 
		}
	 }
	for(int i = 0 ; i < ans.size() - 1  ; i++)
	{
		printf("%d " , ans[i]); 
	 } 
	 printf("%d\n" , ans[ans.size()-1]);
}
int main()
{
	int a , b;
	while(~scanf("%d%d" , &n , &m))	
	{
		init();
		while(m--)
		{
			scanf("%d%d" , &a , &b);
			if(vis[a][b] == 0)//重边 
			{
				edge[a].push_back(b);
				in[b]++;
				vis[a][b] = 1;
			}
		 } 
		 solve();
	}
	
	return 0;
 } 
 /*
 10 9 
 6 4
 3 9
 5 7
 4 1 
 9 2
 7 8
 1 10
 2 10
 8 10 
 */
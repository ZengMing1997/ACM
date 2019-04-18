#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
vector<int>G[maxn] , Index;
int col[maxn] , vis[maxn] , flag;
void dfs(int u,int cur)
{
    col[u] = cur;
    vis[u] = 1;
    for(auto v : G[u])
    {
        if((col[v] == col[u]) && col[v]) flag = 1;
        if(!vis[v])
        {
            if(cur & 1) dfs(v,2);
            else dfs(v,1);
        }
    }
}
int main()
{
    int n , m;
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < m ; i++)
    {
        int u , v;scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
        Index.push_back(u);
    }
    dfs(1,1);
    if(flag) puts("NO");
    else
    {
        puts("YES");
        for(auto i : Index) cout<<col[i]-1;puts("");
    }
}
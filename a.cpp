#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 10;
int p[maxn] , c[maxn] , k[maxn] , ban[maxn] , vis[maxn] , match[maxn] , ans[maxn];
vector<int>G[maxn];
int dfs(int u)
{
    for(auto v : G[u])
    {
        if(!vis[v])
        {
            vis[v] = 1;
            if(match[v] == -1 || dfs(match[v]))
            {
                match[v] = u;
                //match[u] = v;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int n , m;
    //freopen("/home/zengming/桌面/in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i <= n ; i++) match[i] = -1;
    for(int i = 1 ; i <= n ; i++) scanf("%d",&p[i]);
    for(int i = 1 ; i <= n ; i++) scanf("%d",&c[i]);
    int d;scanf("%d",&d);
    for(int i = 1 ; i <= d ; i++) scanf("%d",&k[i]),ban[k[i]] = 1;
    for(int i = 1 ; i <= n ; i++)
    {
        if(!ban[i]) G[p[i]].push_back(c[i]);
    }
    for(int i = d , j = 0; i >= 1 ; i--)
    {
        while(1)
        {

            memset(vis,0,sizeof(vis));
            if(dfs(j))j++;
            else {break;}
        }
        ans[i] = j;
        G[p[k[i]]].push_back(c[k[i]]);
    }
    for(int i = 1 ; i <= d ; i++) cout<<ans[i]<<endl;
}

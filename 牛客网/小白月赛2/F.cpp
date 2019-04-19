#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;
vector<int>G[maxn];
bool dfs(int u,int fa)
{
    for(auto v :G[u])
    {
        if(v == fa) continue;
        if(!dfs(v,u)) return 1;
    } 
    return 0;

}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,r;
        scanf("%d%d",&n,&r);
        for(int i = 0 ; i <= n ; i++) G[i].clear();
        for(int i = 0 ; i < n - 1 ; i++)
        {
            int u ,v;scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int te = dfs(r,0);
        if(te == 1) puts("Gen");
        else puts("Dui"); 
    }
}
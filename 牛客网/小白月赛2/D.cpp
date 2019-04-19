#include <bits/stdc++.h>
using namespace std;
const int maxn = 34;
int du[maxn] ,p[maxn];
int getf(int x)
{
    return x == p[x] ? x : p[x] = getf(p[x]);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(du,0,sizeof(du));
        for(int i = 1 ; i <= n ; i++) p[i] = i;
        for(int i = 0 ; i < m ; i++)
        {
            int u , v;scanf("%d%d",&u,&v);
            if(u == v) continue;
            int dx = getf(u);
            int dy = getf(v);
            if(dx != dy) p[dx] = dy;
            du[u]++,du[v]++;
        }
        int flag = 0;
        int te = 0 , ans = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            if(du[i]%2) ans++;
            if(getf(i) == i) te++;
        }
        if(ans > 2 || te > 1) puts("Xun");
        else  puts("Zhen");
    }
}
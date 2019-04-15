#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
#define INF 0x3f3f3f3f
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
vector<int>G[maxn];
int dfn[maxn] , sz;
int a[maxn<<2] , b[maxn<<2] , ladd[maxn<<2] , radd[maxn<<2] , lminus[maxn<<2] , rminus[maxn<<2] , co[maxn<<2] , sum[maxn<<2];
void dfs(int u,int fa)
{
    dfn[++sz] = 0;
    dfn[++sz] = u;
    for(auto v : G[u])
    {
        if(v == fa) continue;
        cout<<v<<" " << u <<endl;
        dfs(v,u);
    }
    dfn[++sz] = -1;
}
void pushup(int rt)
{
    int A = a[rt<<1] , B = b[rt<<1] , C = a[rt<<1|1] , D = b[rt<<1|1];
    sum[rt] = max(sum[rt<<1] ,sum[rt<<1|1] );
    sum[rt] = max(sum[rt],radd[rt<<1] + lminus[rt<<1|1]);
    sum[rt] = max(sum[rt],rminus[rt<<1] + radd[rt<<1|1]);
    radd[rt] = max(rminus[rt<<1] + C + D , radd[rt<<1] + D - C);
    radd[rt] = max(radd[rt<<1|1] , radd[rt]);
    ladd[rt] = max(lminus[rt<<1] + A + B , ladd[rt<<1] + A - B);
    ladd[rt] = max(ladd[rt] , ladd[rt<<1]);
    rminus[rt] = max(rminus[rt<<1] + C - D,rminus[rt<<1|1]);
    lminus[rt] = max(rminus[rt<<1|1] + A - B,lminus[rt<<1]);
    if(B > C) a[rt] = A - B + C , b[rt] = D;
    else a[rt] = A , b[rt] = B - C + D;
}
void build(int l,int r,int rt)
{
    if(l == r)
    {
        sum[rt] = -INF;
        if(dfn[l] == 0) a[rt] = 1;
        else if(dfn[l] == -1) b[rt] = 1;
        else ladd[maxn<<2] = 0 , radd[maxn<<2]  = 0 , lminus[maxn<<2] = 0, rminus[maxn<<2] = 0;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int pos,int l,int r,int rt)
{
    if(l == r)
    {
        sum[rt] = -INF;
        a[rt] = 0 , b[rt] = 0;
        if(dfn[l] == 0) a[rt] = 1;
        else if(dfn[l] == -1) b[rt] = 1;
        else if(co[dfn[l]]) ladd[maxn<<2] = 0 , radd[maxn<<2]  = 0 , lminus[maxn<<2] = 0, rminus[maxn<<2] = 0; // 黑灯
        else if(!co[dfn[l]]) ladd[maxn<<2] = 0 , radd[maxn<<2]  = -INF, lminus[maxn<<2] = -INF, rminus[maxn<<2] = -INF;
        return ;
    }
    int m = (r+l)/2;
    if(m >= pos) update(pos,lson);
    if(m < pos) update(pos,rson);
    pushup(rt);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n - 1 ; i++)
    {
        int u , v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1 ; i <= n ; i++) co[i] = 1;
 
    dfs(1,0);
    build(1,sz,1);
    int Q , black = n;
    scanf("%d",&Q);
    while(Q--)
    {
        string op;
        cin>>op;
        if(op == "G")
        {
            printf("%d\n",sum[1]);
        }
        else
        {
            int pos ;scanf("%d",&pos);
            if(co[pos]) black--;
            else black++;
            co[pos] = co[pos]^1;
            update(pos,1,sz,1);
        }
    }
}

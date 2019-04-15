#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int a[maxn] , C[maxn], Gcd[maxn<<2] , sum[maxn<<2];
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b,a%b);
}
void pushup(int rt)
{
    Gcd[rt] = gcd(Gcd[rt<<1] , Gcd[rt<<1|1]);
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void build(int l ,int r,int rt)
{
    if(l == r)
    {
        Gcd[rt] = C[l];
        sum[rt] = C[l];
        return ;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int pos,int val,int l,int r,int rt)
{
    if(l == r)
    {
        Gcd[rt] += val;
        sum[rt] += val;
        return ;
    }
    int m = (l+r)>>1;
    if(pos <= m) update(pos,val,lson);
    else update(pos,val,rson);
    pushup(rt);
}
int query1(int L,int R,int l,int r,int rt)
{
    if(L > R) return 0;
    if(l >= L && R >= r) return Gcd[rt];
    int m = (l+r)>>1;
    if(R <= m) return query1(L,R,lson);
    else if(L > m) return query1(L,R,rson);
    else return gcd(query1(L,m,lson),query1(m+1,R,rson));
}
int query2(int L,int R,int l,int r,int rt)
{
    if(L > R) return 0;
    if(l >= L && R >= r) return sum[rt];
    int m = (l+r)>>1;
    if(R <= m) return query2(L,R,lson);
    else if(L > m) return query2(L,R,rson);
    else return query2(L,m,lson) + query2(m+1,R,rson);
}
int main()
{
    int n ,m;
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ; i++) scanf("%d",&a[i]) , C[i] = a[i] - a[i-1];
    build(1,n,1);
    while(m--)
    {
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if(op == 1) printf("%d\n",gcd(query1(l+1,r,1,n,1),query2(1,l,1,n,1))) ;//, cout<<query1(l+1,r,1,n,1) << "   " << query2(1,l,1,n,1)<<endl;
        else
        {
            int u;scanf("%d",&u);
            update(l,u,1,n,1);
            if(r < n);
            update(r+1,-u,1,n,1);
        }
    }
}
/*
7 10
3 6 9 12 11 14 16
1 1 3
2 5 5 4
1 1 5

*/
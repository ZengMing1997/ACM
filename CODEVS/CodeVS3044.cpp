#include <bits/stdc++.h>
#define lson l , m , rt<<1
#define rson m+1,r,rt<<1|1
const int maxnN = 220; 
using namespace std;
struct Seg
{
	double l,r,h;
	int f;
    Seg(){}
	Seg(double a,double b,double c,double d):l(a),r(b),h(c),f(d){}
	bool operator < (const Seg &cmp) const 
	{
		return h<cmp.h;
	}
}e[maxnN];
struct node
{
	int cnt;
	double len;
}sum[maxnN<<2];
double X[maxnN];
void pushdown(int l,int r,int rt)
{
	if(sum[rt].cnt)sum[rt].len = X[r+1] - X[l];
	else if(l == r) sum[rt].len = 0;
	else sum[rt].len = sum[rt<<1].len+sum[rt<<1|1].len;
}
void update(int L,int R,int l,int r, int rt,int val)
{
	if(L<=l && R>=r)
	{
		sum[rt].cnt += val;
		pushdown(l,r,rt);
		return ;
	}
	int m = (l+r)>>1;
	if(L<=m) update(L,R,lson,val);
	if(R>m) update(L,R,rson,val);
	pushdown(l,r,rt);
}
int main()
{
	int n;
	double a,b,c,d;
	int q = 1;
	while(scanf("%d",&n)!=EOF)
	{
		memset(sum,0,sizeof(sum));
		if(n == 0 )break;
		int cnt = 0 ;
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
			X[cnt] = a;
			e[cnt++] =Seg(a,c,b,1);
			X[cnt] = c;
			e[cnt++] = Seg(a,c,d,-1);
		}
		sort(X,X+cnt);
		sort(e,e+cnt);
		int m = unique(X,X+cnt)-X;
		double ans = 0 ;
		for(int i = 0 ; i < cnt; i++)
		{
			int l = lower_bound(X,X+m,e[i].l) - X;
			int r = lower_bound(X,X+m,e[i].r) - X -1;
			update(l,r,0,m,1,e[i].f);
			ans+=(sum[1].len * (e[i+1].h - e[i].h));
		}
		printf("%.2lf\n",ans);
	}
	return 0;
} 
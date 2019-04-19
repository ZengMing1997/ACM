#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
long long a[maxn];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int ans = 0;
    for(int i = 1 ; i <= n ; i++) scanf("%d",&a[i]) , ans = ans ^ a[i];
    for(int i = 1 ; i <= m ; i++)
    {
        int pos,val;scanf("%d%d",&pos,&val);
        ans ^= a[pos];
        a[pos] = val;
        ans ^= val;
        if(ans == 0) puts("Li");
        else puts("Kan");
    }
}
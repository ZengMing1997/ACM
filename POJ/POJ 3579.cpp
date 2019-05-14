#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;
int a[maxn],n,m;
bool check(int x)
{
    int cnt = 0;
    for(int i = 0 ; i < n ; i++)
    {
        int Index = n - (lower_bound(a,a+n,x+a[i]) - a);
        cnt += Index;
    }
    return cnt > m;
}
int main()
{
    
    while(scanf("%d",&n)!=EOF)
    {
        m = n*(n-1)/4;
        for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
        sort(a,a+n);
        int l = a[0] , r = a[n-1] - a[0];
        int ans = 0;
        while(l <= r)
        {
            int m = (l+r)/2;
            if(check(m)) l = m + 1 , ans = m;
            else r = m-1;
        }
        cout<<ans<<endl;

    }
}
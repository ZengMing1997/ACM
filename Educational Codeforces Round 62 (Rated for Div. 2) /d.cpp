#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;
int a[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    long long ans = 0;
    for(int i = 2 ; i <= n - 1; i ++)
    {
        ans += i*(i+1);
    }
    cout<<ans<<endl;
}
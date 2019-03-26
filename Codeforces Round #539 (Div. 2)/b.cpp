#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4+10;
int a[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    int sum = 0 , ans = 0;
    for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]) , sum += a[i];
    sort(a,a+n);
    //ans = sum;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 2 ; j <= sqrt(a[i]) ; j++)
        {
            if(a[i] % j == 0)
            {
               ans = min(ans, sum - (a[i] - a[i] / j + a[0]  - a[0] * j));
            }
        }
    }
    cout<<ans<<endl;

}
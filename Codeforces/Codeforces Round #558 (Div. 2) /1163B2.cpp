#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int a[maxn] , b[maxn]; // vis数组表示的是i这个数字出现了多少次 ，a数组表示的是 出现i次的数有几个
int main()
{
  int n , ans , MAX = -1;
  scanf("%d",&n);
  for (int i = 1; i <= n; i++) {
        int k;scanf("%d", &k);
        b[a[k]]--;
        a[k]++;
        b[a[k]]++;
        MAX = max(MAX, a[k]);
        if (b[1] == i) ans = i;
        else if (b[i] == 1) ans = i;
        else if (b[1] == 1 && b[MAX] * MAX == i - 1) ans = i;
        else if ((b[MAX - 1] + 1) * (MAX - 1) == i - 1) ans = i;
    }
  cout<<ans<<endl;
}

/*
*/
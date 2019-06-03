#include <bits/stdc++.h>
using namespace std;
const int maxn = 50 + 10;
int a[maxn];
int main()
{
  int n , k;
  scanf("%d%d",&n,&k);
  for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
  int ans = 0;
  for(int i = 1 ; i <= min(k,n); i++) // 取i个
  {
    for(int j = 0 ; j <= i ; j++) // 左边j个 右边 i-j个
    {
      int sum = 0;
      vector<int>v;
      for(int l = 0 ; l < j ; l ++) v.push_back(a[l]) , sum += a[l];
      for(int l = n - 1 ; l >= n - (i - j); l--) v.push_back(a[l]) , sum += a[l];
      sort(v.begin(),v.end());
      for(int l = 0 ; l < k - i ; l++)
      {
        if(v[l] < 0) sum -= v[l];
      }
      ans = max(ans,sum);
    }
  }
  cout<<ans<<endl;
}
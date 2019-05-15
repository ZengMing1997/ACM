#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
const int MOD = 998244353;
pair<long long,int> a[maxn] , b[maxn];
int main()
{
  int n;
  scanf("%d",&n);
  for(int i = 1 ; i <= n ; i++)
  {
    scanf("%lld",&a[i].first);
    a[i].second = i;
    a[i].first = a[i].first * i * (n-i+1);
  }
  for(int i = 1 ; i <= n ; i++) scanf("%lld",&b[i].first);
  sort(a+1,a+n+1);
  sort(b+1,b+n+1,[](pair<long long ,int> A , pair<long long ,int > B)
  {
    return A.first > B.first;
  });
  for(int i = 1 ; i <= n ; i++) b[i].second = a[i].second;
  sort(a+1,a+n+1,[](pair<long long ,int> A , pair<long long ,int > B)
  {
    return A.second > B.second;
  });
  sort(b+1,b+n+1,[](pair<long long ,int> A , pair<long long ,int > B)
  {
    return A.second > B.second;
  });
  long long ans = 0;
  for(int i = 1 ; i <= n ; i++)
  {
    ans = (ans + a[i].first % MOD * b[i].first) % MOD;
  }
  cout<<ans<<endl;
}
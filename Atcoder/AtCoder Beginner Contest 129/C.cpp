#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
const int MOD = 1000000007;
int a[maxn] , sum[maxn];
int main()
{
  int n , m;
  scanf("%d%d",&n,&m);
  int one = 0 , two = 0;
  for(int i = 0 ; i < m ; i++)
  {
    scanf("%d",&a[i]);
    if(a[i] == 1) one ++;
    if(a[i] == 2) two++;
  }
  if(one && two) sum[1] = 0 , sum[2] = 0;
  else if(one) sum[1] = 0 ,sum[2] = 1;
  else if(two) sum[1] = 1,sum[2] = 0;
  else sum[1] = 1, sum[2] = 2;
  int t = 0;
  for(int i = 0 ; i < m ; i++)
  {
    if(a[i] > 2) {t = i; break;}
  }
  //cout<<t<<endl;
  for(int i = 3 ; i <= n ; i++)
  {
    if(i == a[t]) sum[i] = 0, t++;
    else sum[i] = (sum[i-1] + sum[i-2]) % MOD;
  }
  cout<<sum[n]<<endl;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int a[maxn];
int main()
{
  int n;
  scanf("%d",&n);
  int p = 1;
  for(int i = 2 ; i <= n; i++)
  {
    if(a[i]) continue;
    for(int j = i ; j <= n; j += i) a[j] = p;
    p++;
  }
  for(int i = 2 ; i <= n; i++) printf("%d ",a[i]);
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int a[maxn];
vector<pair<int,int> >o,e;
int main()
{
  int n;
  scanf("%d",&n);
  int flag1 = 0 , flag2 = 0;
  for(int i = 0 ; i < n ; i++)
  {
    int t;scanf("%d",&a[i]);
    if(a[i] & 1)
    {
      flag1 = 1;
    }
    else flag2 = 1;
  }
  if(flag1 && flag2 ) sort(a,a+n);
  for(int i = 0 ; i < n ; i++) cout<<a[i]<<" ";puts("");
}
//1 2 1 2 1 2 3 1 2 1 3m 
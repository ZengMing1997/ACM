#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  string a;
  scanf("%d",&n);
  cin>>a;
  int te = 0 , ans = 0 , cur = 0;
  for(int i = 0 ; i <= n ; i++)
  {
    int cur = i;
    for(int j = 0 ; j < n ; j++)
    {
      if(a[j] == '+') cur++;
      else cur--;
      if(cur == -1) break;
    }
    if(cur != -1) {cout<<cur<<endl;return 0;}
  }
  cout<<n<<endl;
}
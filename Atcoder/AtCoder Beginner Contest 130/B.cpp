#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n , m;
  scanf("%d%d",&n,&m);
  int t = 0 , ans = 0;
  for(int i = 0 ; i < n ; i++)
  {
    int te;scanf("%d",&te);
    if(t > m) {printf("%d\n",i);return 0;}
    t += te;
  }
  if(t <= m)  cout<<n+1<<endl;
  else cout<<n<<endl;
}
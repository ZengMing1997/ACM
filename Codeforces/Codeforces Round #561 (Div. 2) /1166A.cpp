#include <bits/stdc++.h>
using namespace std;
map<char,int>M;
int f(int x)
{
  return x*(x-1)/2;
}
int main()
{
  int n ;
  scanf("%d",&n);
  char te[111];
  for(int i = 0 ; i < n ; i++)
  {
    scanf("%s",&te);
    M[te[0]]++;
  }
  int ans = 0;
  for(auto i:M)
  {
    if(i.second % 2)
    {
      ans += f(i.second/2) + f(i.second/2+1);
    }
    else ans += 2*f(i.second/2);
  }
  cout<<ans<<endl;
}
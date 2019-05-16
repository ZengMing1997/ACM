#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
    string s;
    int n;
    cin>>n>>s;
    if(s.size() < 11) {puts("NO");continue;}
    int flag = 0;
    for(int i = 0 ; i < n ; i++)
    {
      if(s[i] == '8')
      {
        
        if(n - i >= 11)
        {
          puts("YES");
          flag = 1;
          break;
        }
      }
    }
    if(flag == 0) puts("NO");
  }
}
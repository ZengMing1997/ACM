#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
char ch[maxn];
int main()
{
  int n;
  scanf("%d%s",&n,ch+1);
  int i = 1;
  string ans;
  while(i <= n)
  {
    int j = i+1;
    while(ch[i] == ch[j]) j++;
    if(j <= n && ch[i] != ch[j])
    {
      ans += ch[i];
      ans += ch[j];
    }
    
    i = j+1;
  }
  cout<<n-ans.size()<<endl;
  cout<<ans<<endl;
}
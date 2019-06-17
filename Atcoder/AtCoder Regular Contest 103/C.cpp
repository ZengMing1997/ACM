#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int main()
{
  char s[maxn];
  cin>>s+1;
  int len = strlen(s+1);
  if(s[len] == '1' || s[1] == '0')
  {
    puts("-1");
    return 0;
  }
  for(int i = 1 ; i < len ; i++)
  {
    if(s[i] != s[len - i])
    {
      puts("-1");
      return 0;
    }
  }
  int root = 1;
  for(int i = 2 ; i <= len ; i++)
  {
    cout<<root<<" "<<i<<endl;
    if(s[i-1] == '1') root = i;
  }
}
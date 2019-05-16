#include <bits/stdc++.h>
using namespace std;
int p[7] = {4,8,15,16,23,42};
int main()
{
  vector<int>V;
  for(int i = 0 ; i < 4 ; i++)
  {
    printf("? %d %d\n",i+1,i+2);
    fflush(stdout);
    int t;
    scanf("%d",&t);
    V.push_back(t);
  }
  do{
    int flag = 0;
    for(int i = 0 ; i < 4 ; i++)
    {
      if(p[i] * p[i+1] != V[i]) {flag = 1 ;break;}
      
    }
    if(flag == 0)
    {
      printf("! ");
      for(int i = 0 ; i < 6 ; i++) printf("%d ",p[i]);puts("");
      return 0;
    }
  }while(next_permutation(p,p+6));
}
//32 120 240 368
#include <bits/stdc++.h>
using namespace std;
vector<int>A,B;
int main()
{
  int n , a , x , b , y;
  scanf("%d%d%d%d%d",&n,&a,&x,&b,&y);
  if(x == n) x = 0;
  if(y == n) y = 0;
  for(int i = a ; i <= n + a; i++)
  {
    A.push_back(i%n);
    if(i%n == x) break;
  }
  for(int i = b ; i >= b - n; i--)
  {
    //cout<<i<<"  " << b-n<<endl;
    B.push_back(((i + n) % n + n) % n);
    if(((i + n) % n + n) % n == y) break;
  }
  for(int i = 0 ; i < min(A.size(),B.size());i++)
  {
    //printf("%d %d\n",A[i],B[i]);
    if(A[i] == B[i])
    {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
}
/*
10 9 10 3 4
*/
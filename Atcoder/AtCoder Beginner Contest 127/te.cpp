#include <bits/stdc++.h>
using namespace std;
priority_queue<int> H;
priority_queue<int,vector<int>, greater<int> > L;
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int a;
    scanf("%d",&a);
    H.push(a) , L.push(a);
    if(H.top() > L.top())
    {
      int x = H.top(); H.pop();
      int y = L.top(); L.pop();
      H.push(y) , L.push(x);  
    }
    printf("%d \n",H.top());
  }
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
  string te;
  cin>>te;
  int t1 = 0 , t2 = 0;
  for(int i = 0 ; i < 2 ; i++)
  {
    t1 = t1 * 10 + (te[i] - '0');
  }
  for(int i = 2 ; i < 4 ; i++)
  {
    t2 = t2 * 10 + (te[i] - '0');
  }
  //cout<<t1 <<" " << t2<<endl;
  if(t1 <= 12 && t1 > 0 && (t2 >= 13 || t2 == 0)) puts("MMYY");
  else if((t1 >= 13 || t1 == 0) && t2 <= 12 && t2 > 0) puts("YYMM");
  else if(t1 <= 31 && t2 <= 31 && t1 != 0 && t2 != 0) puts("AMBIGUOUS");
  else puts("NA");


}
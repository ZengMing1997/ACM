 #include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  scanf("%d",&n);
  int A = 0 , B = 0 , All = 0 , AB = 0;
  for(int i = 0 ; i < n ; i++)
  {
    string te; cin>>te;
    if(te[0] == 'B' && te[te.size()-1] == 'A') AB++;
    else if(te[0] == 'B') B++;
    else if(te[te.size()-1] == 'A') A++;
    for(int j = 1 ; j < te.size() ; j++)
    {
      if(te[j-1] == 'A' && te[j] == 'B') All++;
    }
  }
  if(AB)
  {
    All += AB-1;
    if(A) All++, A--;
    if(B) All++, B--; 
  }
  //cout<<All <<"  " << A << B<<endl;
  cout<<min(A,B) + All<<endl;
}
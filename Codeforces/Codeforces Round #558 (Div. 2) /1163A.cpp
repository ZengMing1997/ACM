#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(m==0)return cout<<1,0;
    cout<<min(m,min(n-m,n/2))<<endl;
}
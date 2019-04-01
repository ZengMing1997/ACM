#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,l,c,d,p,nl,np;
    scanf("%d%d%d%d%d%d%d%d",&n,&k,&l,&c,&d,&p,&nl,&np);
    int t = k*l;
    int o = c*d;
    cout<<min(o,min(t/nl,p/np))/n<<endl;
}
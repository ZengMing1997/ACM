#include <bits/stdc++.h>
using namespace std;
string a;
vector<int>V;
int main()
{
    int n;
    scanf("%d",&n);
    cin>>a;
    for(int i = 0 ; i <= n - 11 ; i++)
    {
        if(a[i] == '8') V.push_back(i);
    }
    int pos = (n-11)/2+1;
    //cout<<pos<<"  " << V.size()<<endl;
    if(pos <= V.size()) puts("YES");
    else puts("NO");
    return 0;
}
/*
29
88811188118181818118111111111
*/
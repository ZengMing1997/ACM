#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string a;
        cin>>a;
        int flag = 0;
        sort(a.begin() , a.end());
        for(int i = 1 ; i < a.size() ; i++)
        {
            if(a[i] - a[i-1] != 1)
            {
                flag = 1;
                puts("No");
                break;
            }
        }
        if(!flag)puts("Yes");
    }
}
/*
8
fced
xyz
r
dabcef
az
aa
bad
babc
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        int flag = 0;
        for(int i = 0 ; i < n/2; i++)
        {
            if(s[i] != s[n-i-1] && abs(s[i] - s[n-i-1])!= 2) 
            {
                puts("NO");
                flag = 1;break;
            }
        }
        if(!flag) puts("YES");
    }
}
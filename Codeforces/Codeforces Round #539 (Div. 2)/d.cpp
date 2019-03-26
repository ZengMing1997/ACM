#include <bits/stdc++.h>
using namespace std;
string te;
int check(int len)
{
    for(int i = 0 ; i < len ; i++)
    {
        if(te[i] != te[len-i-1]) return 1;
    }
    return 0;
}
void checkim(string ch)
{
    for(int i = 0 ; i + 1< ch.size()/2 ; i++)
    {
        if(ch[i] != ch[i+1])
        {
            return ;
        }
    }
    puts("Impossible");
    exit(0);
}
void check1()
{
    if(te.size() & 1) return ;
    int len = te.size();
    while(len)
    {
        len = len/2;
        if(check(len))
        {
            puts("1");
            exit(0);
        }
        else if(len&1) return ;
    }
}
int main()
{
    cin>>te;
    checkim(te);
    check1();
    puts("2");
    return 0;
}
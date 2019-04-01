#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e9;
vector<long long>V ,prime;
int vis[maxn];
int main()
{
    long long p;
    scanf("%lld",&p);
    if(p == 1) {puts("1\n0");return 0;}
    
    int pos = 0;
    while(p > 1)
    {
        while(p%prime[pos] == 0)
        {
            V.push_back(prime[pos]);
            p = p/prime[pos];
        }
        pos++;
    }
    if(V.size() > 2)
    {
        printf("1 %lld\n",prime[0]*prime[1]);
    }
    else puts("2");

}
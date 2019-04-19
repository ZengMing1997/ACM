#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int main()
{
    int n,m;string Name,score;
    scanf("%d%d",&n,&m);
    string corr;
    cin>>corr;
    int MAX = 0;
    string ansName;
    for(int i = 0 ; i < m ; i++)
    {
        cin>>Name >> score;
        if(i == 0) ansName = Name;
        int te = 0 ;
        for(int j = 0 ; j < score.size() ; j++)
        {
            if(score[j] == corr[j]) te++;
        }
        if(te > MAX)
        {
            ansName = Name;
            MAX = te;
        }
        else if(te == MAX && ansName > Name)
        {
            ansName = Name;
        }
    }
    printf("%s\n%.2f\n",ansName.c_str() , 100.00 * MAX/n);
}
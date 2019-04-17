#include <bits/stdc++.h>
using namespace std;
int Index[10] = {0,1,2,3,1,3,2,1};
int A[10] , B[10];
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int MAX = min(a/3,min(b/2,c/2));
    int ans = MAX * 7;
    A[1] = a - MAX*3 ,A[2] = b - MAX*2 ,A[3] = c - MAX*2;
    int sum = 0;
    for(int i = 1 ; i <= 7 ; i++)
    {
        int j = i , te = 0;
        B[1] = A[1] , B[2] = A[2] , B[3] = A[3];
        while(B[1] ||B[2] ||B[3])
        {
            if(B[Index[j]] == 0) break;
            B[Index[j]]--;
            te ++;
            j = j % 7 + 1;
        }
        sum = max(sum,te);
    }
    printf("%d\n",ans + sum);

}
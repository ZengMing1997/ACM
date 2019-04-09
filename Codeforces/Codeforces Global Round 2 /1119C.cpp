#include <bits/stdc++.h>
using namespace std;
const int maxn = 555;
int a[maxn][maxn] , b[maxn][maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++) scanf("%d",&a[i][j]);
	}
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++) scanf("%d",&b[i][j]);
	}
	for(int i = 0 ; i < n ; i++)
	{
		int cnt = 0;
		for(int j = 0 ; j < m ; j++)
		{
			if(a[i][j] != b[i][j]) cnt++;
		}
		if(cnt & 1) {puts("No");return 0;}
	}
	for(int i = 0 ; i < m ; i++)
	{
		int cnt = 0;
		for(int j = 0 ; j < n ; j++)
		{
			if(a[j][i] != b[j][i]) cnt++;
		}
		if(cnt & 1) {puts("No");return 0;}
	}
	printf("Yes");
}
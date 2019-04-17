#include <bits/stdc++.h>
using namespace std;
vector<int>A,B;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		A.clear();B.clear();
		int n , m;
		scanf("%d%d",&n,&m);
		for(int i = 0 ; i < n ; i++)
		{
			int t;scanf("%d",&t);
			if(t < 0) B.push_back(-t);
			else A.push_back(t);
		}
		sort(A.begin(),A.end(),[](int a,int b){return a > b;});
		sort(B.begin(),B.end(),[](int a,int b){return a > b;});
		long long ans = 0;
		if(A.size() == 0)
		{
			ans += B[0];
			for(int i = m ; i < B.size() ; i += m) ans += B[i]*2;
		}
		else if(B.size() == 0)
		{
			ans += A[0];
			for(int i = m ; i < A.size() ; i += m) ans += A[i]*2;
		}
		else if(A[0] > B[0])
		{
			for(int i = 0 ; i < B.size() ; i += m) ans += B[i]*2;
			ans += A[0];
			for(int i = m ; i < A.size() ; i += m) ans += A[i]*2;
		}
		else 
		{
			for(int i = 0 ; i < A.size() ; i += m) ans += A[i]*2;
			ans += B[0];
			for(int i = m ; i < B.size() ; i += m) ans += B[i]*2;
		}
		cout<<ans<<endl; 
	}
}

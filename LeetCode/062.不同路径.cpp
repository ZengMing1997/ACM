/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+100][n+100];
        memset(dp,0,sizeof(dp));
        dp[1][1] = 1;
        for(int i = 1; i <= m; i++) dp[1][i] = 1;
        for(int i = 1; i <= n; i++) dp[i][1] = 1;
        for(int i = 2; i <= n; i++) {
            for(int j = 2; j <= m; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};


/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> >ans(n);
        for(int i = 0 ; i < n ; i++) {
            ans[i].resize(n);
        }
        puts("");
        int l = 0 , r = n - 1, top = 0, down = n - 1 , cnt = 1;
        while(cnt <= n*n){
            for(int i = l ; i <= r ; i ++) ans[top][i] = cnt++ , printf("ans[%d][%d] = %d ",top,i,ans[top][i]); puts("");
            top++;
            for(int i = top ; i <= down ; i++) ans[i][r] = cnt++ , printf("ans[%d][%d] = %d ",i,r,ans[i][r]);; puts("");
            r--;
            if(r < 0) break;
            for(int i = r ; i >= l ; i--) ans[down][i] = cnt++ , printf("ans[%d][%d] = %d ",down,i,ans[down][i]);; puts("");
            down--;
            for(int i = down ; i >= top ; i--) ans[i][l] = cnt++ , printf("ans[%d][%d] = %d ",i,l,ans[i][l]); puts("");
            l++;
        }
        return ans;
    }
};


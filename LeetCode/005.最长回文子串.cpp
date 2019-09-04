/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int len = s.size();
        vector<vector<int> > dp(len,vector<int> (len));
        int st = 0 , le = 1 ;
        for(int i = 0 ; i < len ; i++) {
            dp[i][i] = 1;
            if(i) {
                if(s[i] == s[i-1]) {
                    dp[i-1][i] = 1;
                    st = i - 1 , le = 2;
                }
            }
        }
        for(int i = 3 ; i <= len ; i++) {
            for(int l = 0 ; l + i - 1 < len ; l++) {
                int r = l + i - 1;
                if(dp[l+1][r-1] && s[l] == s[r]) {
                    st = l , le = i;
                    dp[l][r] = 1;
                }
            }
        }
        //cout<< st << l <<endl;
        return s.substr(st,le);
    }
};


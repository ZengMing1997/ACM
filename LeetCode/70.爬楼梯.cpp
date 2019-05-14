/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        long long a = 2 , b = 1;
        for(int i = 3 ; i <= n ; i++)
        {
            int te = a;
            a = a + b;
            b = te;
        }
        return a;
    }
};


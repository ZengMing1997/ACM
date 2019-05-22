/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0 ; i < len ; i++)
        {
            if(nums[i] == i + 1 || nums[i] <= 0) continue;
            int x = nums[i];
            while(x >= 1 && x <= len && x  != nums[x-1]) swap(x,nums[x-1]);   
        }
        for(int i = 0 ; i < len ; i++)
        {
            if(i + 1 != nums[i]) return i+1;
        }
        return nums.size()+1;
    }
};


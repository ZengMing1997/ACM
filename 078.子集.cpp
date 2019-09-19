/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int> >ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0;i < (1<<len); i++) {
            vector<int>V;
            for(int j = 0; j < len ; j++) {
                if(i&(1<<j)) {
                    V.push_back(nums[j]);
                }
            }
            ans.push_back(V);
        }
        return ans;
    }
};


/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ;
        return nums[nums.size()/2];
    }
};


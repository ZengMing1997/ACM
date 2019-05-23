/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0;
        int A = nums[0];
        for(int i = 0 ; i < nums.size() ; i++){
            ans = max(ans+nums[i] , nums[i]);
            A = max(A,ans);
        }
        return A;
    }
};


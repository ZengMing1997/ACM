/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int>ans(len);
        int cur = 1;
        for(int i = 0 ; i < ans.size() ; i++) {
            ans[i] = cur;
            cur *= nums[i]; 
        }
        int k = 1;
        for(int i = ans.size() - 1 ; i >= 0 ; i--) {
            ans[i] *= k;
            k = k * nums[i]; 
        }
        return ans;
    }
};


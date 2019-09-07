/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size() , ans = 0 , MIN = 0x3f3f3f3f;
        for(int i = 0 ; i < len; i++) {
            if(MIN > prices[i]) {
                MIN = prices[i];
            }
            else {
                ans = max(ans,prices[i] - MIN);
            }
        }
        return ans;
    }
};


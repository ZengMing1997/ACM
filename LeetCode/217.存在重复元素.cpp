/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
class Solution {
public:
    set<int>S;
    bool containsDuplicate(vector<int>& nums) {
        for(auto i : nums){
            if(S.find(i) == S.end()) {
                S.insert(i);
            }
            else return true;
        }
        return false;
    }
};


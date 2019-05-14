/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int jw = 1 , len = digits.size()-1;
        for(int i = len ; i >= 0 ; i--)
        {
            digits[i] += jw;
            jw = digits[i]/10;
            digits[i] %= 10;
        }
        if(jw) digits.insert(digits.begin(),jw);
        return digits;
    }
};


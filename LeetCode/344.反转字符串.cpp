/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        for(int i = 0 ; i < len/2 ; i ++) {
            swap(s[i] , s[len-i-1]);
        }
    }
};


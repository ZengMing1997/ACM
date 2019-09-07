/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0) return false;
        for(int i = 0 ; i < 32 ; i++) {
            if((1<<i) == n) return true;
        }
        return false;
    }
};


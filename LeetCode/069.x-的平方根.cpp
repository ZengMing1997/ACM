/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */
class Solution {
public:
    int mySqrt(int x) {
        int l = 0 , r = x;
        while(l<=r)
        {
            int m = (l+r)>>1;
            if(1LL*m*m == x) return m;
            if(1LL*m*m < x) l = m + 1;
            else r = m - 1;
        }
        return r;
    }
};


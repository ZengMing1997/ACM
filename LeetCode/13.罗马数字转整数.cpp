/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>M;
        M['I'] = 1, M['V'] = 5 ,M['X'] = 10 , M['L'] = 50 , M['C'] = 100 , M['D'] = 500 , M['M'] = 1000;
        int ans = 0 , len = s.size();
        for(int i = 1 ; i <= len ; i++)
        {
            if(M[s[i-1]] >= M[s[i]]) ans += M[s[i-1]];
            else ans -= M[s[i-1]];
        }
        return ans;
    }
};


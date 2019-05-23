/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现strStr()
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = -1;
        if(haystack.empty() && needle.empty()) return 0;
        else if(needle.empty()) return 0;
        int len = haystack.size() , len1 = needle.size();
        for(int i = 0 ; i <= len - len1; i++)
        {
            if(haystack[i] == needle[0])
            {
                int flag = 0;
                for(int j = 0 ; j < len1 ; j++)
                {
                    if(haystack[i+j] != needle[j]) {flag = 1;break;}
                }
                if(flag == 0) {ans = i;break;}
            }
        }
        return ans;
    }
};


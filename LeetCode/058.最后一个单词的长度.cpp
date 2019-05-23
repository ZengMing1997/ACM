/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size() - 1;
        int sum = 0;
        int i = len;
        for(;i >= 0 ; i--)
        {
            if(s[i] != ' ') break;
        }
        for(; i >= 0 ;i--)
        {
            if(s[i] == ' ') return sum;
            sum++;
        }
        return sum;
    }
};


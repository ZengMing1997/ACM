/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */
class Solution {
public:
    string reverseWords(string s) {
        string t , ans;
        int len = s.size();
        for(int i = 0 ; i < len ; i++) {
            if(s[i] == ' ') {
                for(int j = t.size() - 1 ; j >=0 ; j--) {
                    ans += t[j];
                }
                ans += ' ';
                t.clear();
            }
            else t += s[i];
        }
        for(int i = t.size() - 1 ; i >= 0 ; i--) {
            ans += t[i];
        }
        return ans;
    }
};


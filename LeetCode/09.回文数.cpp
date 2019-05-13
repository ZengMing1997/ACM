/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
class Solution {
public:
    bool isPalindrome(int x) {
        string a = to_string(x);
        int posl = 0 , posr = a.size()-1;
        while(posl <= posr)
        {
            if(a[posl] != a[posr]) return false;
            posl++,posr--;
        }
        return true;
    }
};


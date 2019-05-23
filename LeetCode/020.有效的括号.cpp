/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for (int i = 0 ; i < s.size() ; i++) {
            switch (s[i]) {
                case '(': 
                case '{': 
                case '[': S.push(s[i]); break;
                case ')': if (S.empty() || S.top()!='(') return false; else S.pop(); break;
                case '}': if (S.empty() || S.top()!='{') return false; else S.pop(); break;
                case ']': if (S.empty() || S.top()!='[') return false; else S.pop(); break;
            }
        }
        return S.empty() ;
    }
};


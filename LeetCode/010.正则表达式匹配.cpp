/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        return dfs(0,s,0,p);
    }
    bool dfs(int s1 , string s ,int p1,string p) {
        if(s1 == s.size()) return true;
        if(p1 == p.size()) return false;
        if(p[p1+1] == '*') {
            if(s[s1] == p[p1] || p[p1] == '.') {
                return dfs(s1+1,s,p1,p) | dfs(s1,s,p1+2,p) | dfs(s1+1,s,p1+2,p);
            }
        }
        else {
            return dfs(s1,s,p1+2,p);
        }
        if(s[s1] == p[p1] || p[p1] == '.') {
            return dfs(s1+1,s,p1+1,p);
        }
        return false;
    }
};
/*int main()
{
    Solution A;
    cout<<A.isMatch("aaa","a");
}
*/


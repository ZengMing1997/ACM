/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有K个重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
 *
 * algorithms
 * Medium (38.45%)
 * Likes:    48
 * Dislikes: 0
 * Total Accepted:    2.2K
 * Total Submissions: 5.6K
 * Testcase Example:  '"aaabb"\n3'
 *
 * 找到给定字符串（由小写字符组成）中的最长子串 T ， 要求 T 中的每一字符出现次数都不少于 k 。输出 T 的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * s = "aaabb", k = 3
 * 
 * 输出:
 * 3
 * 
 * 最长子串为 "aaa" ，其中 'a' 重复了 3 次。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:
 * s = "ababbc", k = 2
 * 
 * 输出:
 * 5
 * 
 * 最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() == 0) return 0;
        int vis[30];
        memset(vis,0,sizeof(vis));
        int ans = 0;
        for(int i = 0 ; i < s.size() ; i++) vis[s[i]-'a']++;
        int flag = 0;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(vis[s[i] - 'a'] < k)
            {
                flag = 1;
                ans = max(longestSubstring(s.substr(0,i),k),longestSubstring(s.substr(i+1,s.size()),k));
                break;
            }
        }
        if(!flag) return s.size();
        return ans;
    }
};


/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cnt = 0;
        for(int i = 0 ; i < nums1.size() ; i++)
        {
            if(nums1[i] == 0) nums1[i] = nums2[cnt], cnt++;
            if(cnt == nums2.size()) break;
        }
        sort(nums1.begin(),nums1.end());
    }
};


/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans , flag = 0;
    int findKthLargest(vector<int>& nums, int k) {
        /*priority_queue<int,vector<int>,greater<int> >Q;
        for(auto i : nums) {
            if(Q.size() < k) Q.push(i);
            else {
                int t = Q.top();
                if(t >= i) continue;
                else {
                    cout<<t << " " << i << endl;
                    Q.pop();
                    Q.push(i);
                }
            }
        }
        return Q.top();*/
        quick(nums,nums.size() - k,0,nums.size()-1);
        return ans;
        
    }
    void quick(vector<int>nums,int k,int l,int r) {
        if(flag) return;
        if(l == r  && l == k) {ans = nums[k] , flag = 1; return ; }
        int index = partition(nums,k,l,r);
        if(index == k ) {
            ans = nums[k];
            flag = 1;
        }
        if(index > l) {
            quick(nums,k,l,index-1);
        }
        if(index < r) {
            quick(nums,k,index+1,r);
        }
    }
    int partition(vector<int>&nums , int k,int l,int r) {
        int L = l-1;
        for(int i = l ; i < r ; i++) {
            if(nums[i] < nums[r]) {
                L++;
                int findKthLargest(vector<int>& nums, int k) {
        /*priority_queue<int,vector<int>,greater<int> >Q;
        for(auto i : nums) {
            if(Q.size() < k) Q.push(i);
            else {
                int t = Q.top();
                if(t >= i) continue;
                else {
                    cout<<t << " " << i << endl;
                    Q.pop();
                    Q.push(i);
                }
            }
        }
        return Q.top();*/
        quick(nums,nums.size() - k,0,nums.size()-1);
        return ans;
        
    }
    void quick(vector<int>nums,int k,int l,int r) {
        if(flag) return;
        if(l == r  && l == k) {ans = nums[k] , flag = 1; return ; }
        int index = partition(nums,k,l,r);
        if(index == k ) {
            ans = nums[k];
            flag = 1;
        }
        if(index > l) {
            quick(nums,k,l,index-1);
        }
        if(index < r) {
            quick(nums,k,index+1,r);
        }
    }
    int partition(vector<int>&nums , int k,int l,int r) {
        int L = l-1;
        for(int i = l ; i < r ; i++) {
            if(nums[i] < nums[r]) {
                L++;
                swap(nums[i],nums[L]);
            }
        }
        L++;
        swap(nums[L],nums[r]);
        return L;
    }swap(nums[i],nums[L]);
            }
        }
        L++;
        swap(nums[L],nums[r]);
        return L;
    }
};
